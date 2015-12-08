#include "Entity/burstshot.h"
#include "Entity/playerentity.h"
#include "Entity/shotentity.h"
#include "Util/timer.h"
#include <QDebug>
#include <QGraphicsEffect>
#include <QLabel>

/**
 * @brief PlayerEntity Constructor
 * @param game current GameState to which Player belongs;
 * @param x beginning horizontal coordinate
 * @param y beginning vertical coordinate
 */
PlayerEntity::PlayerEntity(GameState *game, int x, int y):
    Entity(x,y,":/sprites/player/player1sprite.png"), game(game),
    moveSpeed(300),DIAGONAL(static_cast<float>(qSin(45))),
    haloSize(0), lastShot(0), shotInterval(0.1), energy(0)
{
    polarity = WHITE;
    type = PLAYER;

    //split sprite frames into vector object
    int tileSize = 40;
    int cols = sprite->getWidth()/40;
    int rows = sprite->getHeight()/40;
    //pseudo multidimential container
    frames.resize(cols * rows);

    //copy each frame
    for(int col = 0; col < cols; col ++){
        for(int row = 0; row < rows; row++){
            frames.data()[col + (row * cols)] = s_ptr ( new Sprite(
                        sprite->getRef(),sprite->getImage().copy(
                            tileSize*col, tileSize*row, tileSize, tileSize)));
        }
    }
    currentFrame = 5;
    sprite = frames.at(currentFrame);
    up = down = left = right = trigger = polarize = burst = polarKeyLock = false;

    whiteAura.setColorAt(0, QColor(0,255,255,0));
    whiteAura.setColorAt(0.25, QColor(0,255,255,0));
    whiteAura.setColorAt(0.73, QColor(0,255,255,40));
    whiteAura.setColorAt(0.75, QColor(255,255,255,75));
    whiteAura.setColorAt(0.77, QColor(0,255,255,25));
    whiteAura.setColorAt(1, QColor(0,255,255,0));
    blackAura.setColorAt(0, QColor(255,0,0,0));
    blackAura.setColorAt(0.25, QColor(255,0,0,0));
    blackAura.setColorAt(0.73, QColor(255,0,0,40));
    blackAura.setColorAt(0.75, QColor(255,175,0,75));
    blackAura.setColorAt(0.77, QColor(255,0,0,25));
    blackAura.setColorAt(1, QColor(255,0,0,0));

}

/**
 * @brief Update PlayerEntity coords based on movement and time
 * @param delta timeslice interpolation factor. Time since last movement
 */
void PlayerEntity::move(double delta){

    //bound check, stop moving when reaching edge of screen
    if ((dir.x()  < 0) && (getX()+(delta * dir.x() )<=sprite->getWidth()/2)){
        dir.rx() = 0;
        pos.rx()=sprite->getWidth()/2;
    }
    if((dir.x()  > 0) && (getX()+(delta * dir.x() ) >  game->width()-sprite->getWidth()/2)){
        dir.rx() = 0;
        pos.rx() = game->width()-sprite->getWidth()/2;
    }
    if ((dir.y()  < 0) && (getY()+(delta * dir.y() )<=sprite->getHeight()/2)){
        dir.ry() = 0;
        pos.ry() = sprite->getWidth()/2;
    }
    if((dir.y() > 0) && (getY() +(delta * dir.y()) >  game->height()-sprite->getHeight()/2)){
        dir.ry() = 0;
        pos.ry() = game->height()-sprite->getHeight()/2;
    }

    //move
    pos.rx() += (delta * dir.x() ) ;
    pos.ry() += (delta * dir.y()) ;
    //set hitbox
    hitBox.setRect(getX()-sprite->getWidth()/2,getY()- sprite->getHeight()/2,
                   sprite->getWidth(),sprite->getHeight());
}

/**
 * @brief perform appropriate PlayerEntity logic. Set Movement, change animation
 *  frames, shoot laser, swap polarity, fire burst, etc
 */
void PlayerEntity::doLogic(double delta){
    QHash<QString, bool> keys = game->getKeys();

    up = keys["up"];
    down = keys["down"];
    left = keys["left"];
    right = keys["right"];
    trigger = keys["trigger"];

    if(keys["polarize"]){
        if(!polarKeyLock){
            polarize = keys["polarize"];
            polarKeyLock = true;
        }
    }else{
        polarize = keys["polarize"];
        polarKeyLock = false;
    }

    burst = keys["burst"];

    dir.rx() =0;
    dir.ry()=0;

    if(flinching && Timer::getTime() > flinchTimer){
        flinching = false;
    }
    // resolve the movement of the ship. First assume the ship
    // isn't moving. If either cursor key is pressed then
    // update the movement appropraitely
    if (game->getPlayerControl()){

        //assign movement based on keypresses
        if ((left) && (!right)) {//left
            if ((up) && (!down)) {//upLeft
                //factor for diagonnal movement speed
                setVerticalMovement(DIAGONAL * -moveSpeed);
                setHorizontalMovement(DIAGONAL * -moveSpeed);
            } else if ((down) && (!up)) {//downLeft
                setVerticalMovement(DIAGONAL * moveSpeed);
                setHorizontalMovement(DIAGONAL * -moveSpeed);
            } else {
                setHorizontalMovement(-moveSpeed);//left only
            }
        } else if ((right) && (!left)) {//right
            if ((up) && (!down)) {//up
                setVerticalMovement(DIAGONAL * -moveSpeed);
                setHorizontalMovement(DIAGONAL * moveSpeed);
            } else if ((down) && (!up)) {//down
                setVerticalMovement(DIAGONAL * moveSpeed);
                setHorizontalMovement(DIAGONAL * moveSpeed);

            } else {
                setHorizontalMovement(moveSpeed);//right only
            }
        } else if ((up) && (!down) && (!right) && (!left)) {//up
            setVerticalMovement(-moveSpeed);
        } else if ((down) && (!up) && (!right) && (!left)) {//down
            setVerticalMovement(moveSpeed);
        }

        //shot it shoot button pressed
        if(trigger){
            shoot();
        }
        //swap polarity if polariza button pressed
        if(polarize){
            polarSwap();
        }

        if(burst){
            shootBurst();
        }
    }

    //ship tilt/polarity animations
    if(Timer::getTime() - lastFrameChange > 0.018){
        if(dir.x()  < 0){
            if( currentFrame > 0 +(polarity*11) ){
                currentFrame--;
                lastFrameChange = Timer::getTime();
            }
        }else if(dir.x()  == 0){
            if(currentFrame > 5+(polarity*11)){
                currentFrame--;
                lastFrameChange = Timer::getTime();
            }else if(currentFrame < 5+(polarity*11)){
                currentFrame++;
                lastFrameChange = Timer::getTime();
            }
        }else if(dir.x()  > 0){
            if(currentFrame < 10 + (polarity*11)){
                currentFrame++;
                lastFrameChange = Timer::getTime();
            }
        }
        //bind index withing range range
        currentFrame = (currentFrame + 22)%22;
        sprite = frames.at(currentFrame);

        if(haloSize < sprite->getWidth()){
            haloSize = haloSize + 3> sprite->getWidth() ?sprite->getWidth(): haloSize + 2 ;

        }
    }
}

/**
 * @brief Fire ShotEntity based on current polarity. Add new shots to gamestate
 * playerEntities list
 */
void PlayerEntity::shoot(){
    //skip if interval has yet to pass
    if(Timer::getTime()-lastShot < shotInterval){
        return;
    }
    //capture time
    lastShot = Timer::getTime();

    e_ptr lShot(new ShotEntity(game, getX()-8, getY()-6, polarity));
    e_ptr rShot(new ShotEntity(game, getX()+8, getY()-6, polarity));
    //create new shotEntities and add them to game Qlist<e_ptr>
    game->getPlayerEntities().push_front(lShot);
    game->getPlayerEntities().push_front(rShot);

}

void PlayerEntity::shootBurst()
{
    if(Timer::getTime()-lastShot < shotInterval){
        return;
    }
    lastShot = Timer::getTime();

    e_ptr burst1(new BurstShot(game,getX(),getY(),90,polarity));
    e_ptr burst2(new BurstShot(game,getX(),getY(),-90,polarity));
    game->getPlayerEntities().push_front(burst1);
    game->getPlayerEntities().push_front(burst2);

}

/**
 * @brief Change player polarity from black to white or vice-versa.
 * correct for frame animation lockup
 */

void PlayerEntity::polarSwap()
{
    //inverse polarity
    polarity = polarity == WHITE ? BLACK : WHITE;
    polarize = false;//unset button til next keypress
    haloSize = 0;
    //tilted animation fix
    if(polarity == BLACK && currentFrame == 0){
        currentFrame--;
    }else if(polarity == WHITE && currentFrame == 21){
        currentFrame ++;
    }
    currentFrame = (currentFrame + 22)%22;
//    qDebug() << "Swap";
}

/**
 * @brief draw Entity sprite and related graphics
 * @param painter object with which to draw onto widget context
 */
void PlayerEntity::draw(QPainter *painter)
{

    //set halo colors
    whiteAura.setCenter(pos.x(),pos.y());
    whiteAura.setFocalPoint(pos.x(),pos.y());
    whiteAura.setRadius(haloSize);

    blackAura.setCenter(pos.x(),pos.y());
    blackAura.setFocalPoint(pos.x(),pos.y());
    blackAura.setRadius(haloSize);

    //select halo color based on polarity and draw it
    painter->setBrush(QBrush(polarity == WHITE ? whiteAura: blackAura));
    painter->setPen(Qt::transparent);
    painter->drawEllipse(QPoint(pos.x(),pos.y()),haloSize,haloSize);

    //create shadow effect
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect;
    int shadowOffset = 20;
    int xOffset = (20.0f/(game->width()/2.0f)*getX() - shadowOffset);
    int yOffset = (20.0f/(game->height()/2.0f)*getY() - shadowOffset);
    //set shadow effest
    shadow->setBlurRadius(8);
    shadow->setOffset(xOffset, yOffset);
    shadow->setColor(QColor(0,0,0,115));
    //draw ship with shadoe
    sprite->drawWithEffect(painter, getX()-shadowOffset, getY()-shadowOffset,
                           shadow, shadowOffset);

    //draw hitBox (debug)
//    painter->setPen(polarity == WHITE ? Qt::blue : Qt::red);
//    painter->drawRect(hitBox);


}

void PlayerEntity::collidedWith(const e_ptr &other){
    if(other->getType() == ENEMYSHOT){
        if(polarity == other->getPolarity()){
            energy = energy < 80 ? energy + 1: 80;
        }
    }

}

PlayerEntity::~PlayerEntity()
{

}
int PlayerEntity::getEnergy() const
{
    return energy;
}

void PlayerEntity::setFlinching(double flinchTime)
{
    flinching = true;
    flinchTimer = Timer::getTime() + flinchTime;
}
void PlayerEntity::setThrottleSetting(const throttle &value)
{
    throttleSetting = value;
}








