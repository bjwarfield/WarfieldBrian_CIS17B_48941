#include "Entity/enemyentity.h"
#include "Entity/enemyshotentity.h"
#include "Entity/shotentity.h"
#include "Util/timer.h"


EnemyEntity::EnemyEntity(GameState *game, int x, int y, polarType polarity, Path *path, QString ref):
    Entity(x,y,ref), game(game)
{
    this->path = path;
    this->polarity = polarity;

    this->path = new Path;
    this->path->addNode(Point(700,500));
    this->path->addNode(Point(100,100));
    this->path->addNode(Point(100,500));
    this->path->addNode(Point(700,100));
    this->path->addNode(Point(1000,100));

    currentNode = 0;

    //enemy stats
    maxHealth = 20;
    health = 20;
    value = 100;

    //init status
    hit = false;
    dead = false;
    type = ENEMY;

    target.setX(x);
    target.setY(y+10);

    //init movement
    setVerticalMovement(0);
    setHorizontalMovement(0);

    //assume 2 frames: topDown White/Black polarity
    int cols = 1;
    int rows = 2;
    parseFrames(cols, rows);

    sprite = frames.at(polarity);

    //set Gun pos
    gunX = x;
    gunY = sprite->getHeight() /2;

    //init timers
    startTime = Timer::getTime();
    ticker = moveTicks = lastMove = shotTicks = lastShot = 0;
}

void EnemyEntity::parseFrames(int cols, int rows)
{
    int tileHeight = sprite->getHeight()/rows;
    int tileWidth = sprite->getWidth()/cols;

    frames.resize(cols*rows);

    for(int col = 0; col < cols; col++){
        for(int row = 0; row < rows; row++){
            frames.data()[col + (row * cols)] =
                    s_ptr( new Sprite(sprite->getRef(),
                                      sprite->getImage().copy(
                                          col*tileWidth,
                                          row*tileHeight,
                                          tileWidth,
                                          tileHeight)));
        }
    }
}

void EnemyEntity::draw(QPainter *painter)
{
    painter->save();

    QTransform trans;
    trans.translate(getX(), getY());
    trans.rotate(-pos.angleTo(dir+pos));

    painter->setTransform(trans);


    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    int xOffset = (20.0f/(game->width()/2.0f)*getX() - 20);
    int yOffset = (20.0f/(game->height()/2.0f)*getY() - 20);

    shadow->setBlurRadius(8);
    shadow->setOffset(xOffset, yOffset);
    shadow->setColor(QColor(0,0,0,115));
    sprite->drawWithEffect(painter, -20, -20, shadow,20);

    painter->restore();
    painter->save();

    //hitbox
    painter->setPen(Qt::magenta);
    painter->drawRect(hitBox);

    //current velocity
    painter->setPen(Qt::green);
    painter->drawLine(getX(),
                      getY(),
                      getX() + dir.x(),
                      getY() + dir.y()
                      );
    //desired velocity
    painter->setPen(Qt::blue);
    painter->drawLine(getX(),
                      getY(),
                      getX() + tv.x(),
                      getY() + tv.y());

    //steering
    painter->setPen(Qt::yellow);
    painter->drawLine(getX() + dir.x(),
                      getY() + dir.y(),
                      getX() + dir.x() + (tv.x() - dir.x()) * 0.5f,
                      getY() + dir.y() + (tv.y() - dir.y()) * 0.5f);


    painter->restore();
}

void EnemyEntity::doLogic(double delta)
{
     angle = fmodf((angle + 360) , 360);//bind range between 0 and 360

     //set target to random player position if one exists, else target is straight down
     if(game->getPlayers().size() > 0){
         int idx  = game->rand(0,game->getPlayers().size()-1);
         e_ptr player = game->getPlayers()[idx];
         target.setX(player->getX());
         target.setY(player->getY());
     }else{
         target.setX(getX());
         target.setY(getY()+30);
     }
     elapsed = Timer::getTime() - startTime;

     if(Timer::getTime() - ticker > 0.04){//approx 25ticks/sec
         moveTicks++;
         shotTicks++;
         ticker = Timer::getTime();
     }

    //update hitBox
     hitBox.setCoords(getX() - sprite->getWidth()/2, getY() - sprite->getHeight()/2,
                      getX() + sprite->getWidth()/2, getY() + sprite->getHeight()/2);
     gunX = getX();
     gunY = getY() + sprite->getHeight() /2;


     followPath(delta);
     angle = pos.angleTo(pos + dir);
}

void EnemyEntity::seek(const Point &trgt, double delta)
{
    float dist = pos.distanceTo(trgt);
    tv = (trgt - pos).normalize() * Point(qMin(250.0f,dist) ,qMin(250.0f,dist));
    sv = tv - dir;
    sv = sv * Point(.75*delta, .75*delta);
    dir = dir + sv;
}


bool EnemyEntity::isDead()
{
    return dead;
}

void EnemyEntity::shoot(int speed, const e_ptr &target, float deg)
{

    shoot(speed,QPoint(target->getX(),target->getY()),deg );

}

void EnemyEntity::shoot(int speed, QPoint target, float deg){
    float xDiff = target.x() - getX();
    float yDiff = target.y() - (getY() +( sprite->getHeight()/2));

    float rads = atan2f(xDiff,yDiff);
    gunX = getX();
    gunY = getY() + (sprite->getHeight()/2);

    deg += game->rand(-20,20)/5.0f;
    e_ptr shot(new EnemyShotEntity(game, gunX, gunY, polarity));
    shot->setHorizontalMovement(speed * sin(rads + qDegreesToRadians(deg)));
    shot->setVerticalMovement(speed * cos(rads + qDegreesToRadians(deg)));

    game->getEnemyEntities().push_back(shot);
}

void EnemyEntity::collidedWith(const e_ptr &other)
{
    if(!dead){
        if(other->getType() == SHOT || other->getType() == BURST){

            int dmg = qSharedPointerCast<ShotEntity>(other)->getDmg();
            if(other->getPolarity() == polarity){
                health -= dmg/2;
            }else{
                health -= dmg * 2;
            }

            if(health <= 0){
                dead = true;
                removeThis = true;
            }
        }
    }
}

EnemyEntity::~EnemyEntity()
{
    if(path != NULL){
        delete path;
    }
}


void EnemyEntity::followPath(double delta)
{
    Point target;
    if(path != NULL){
        target = (path->getNodes().data()[currentNode]);
        if(target.distanceTo(pos) <= 40){
            currentNode++;

            if(currentNode >= path->getNodes().size()){
                currentNode = path->getNodes().size() -1;
            }
        }
        seek(target, delta);
        return;
    }
     seek(Point(getX(),getY()+1000), delta);
}


