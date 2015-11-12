#include "playerentity.h"
#include <QDebug>
#include "shotentity.h"

PlayerEntity::PlayerEntity(GameWidget *game, int x, int y):
    Entity(x,y,":/resources/sprites/player/whiteSprite.png"), game(game),
    left(false),    right(false), up(false), down(false), trigger(false),
    polarize(false), moveSpeed(300),DIAGONAL(static_cast<float>(qSin(45))),
    lastShot(0), shotInterval(100),polarity(WHITE)
{

}

void PlayerEntity::move(ms delta){



    //bound check
    if ((dx < 0) && (x+dx/1000<=sprite.getWidth()/2)){
        dx=0;
        x=sprite.getWidth()/2;
    }
    if((dx > 0) && (x+dx/1000 >  game->width()-sprite.getWidth()/2)){
        dx = 0;
        x = game->width()-sprite.getWidth()/2;
    }
    if ((dy < 0) && (y+dy/1000<=sprite.getHeight()/2)){
        dy=0;
        y=sprite.getWidth()/2;
    }
    if((dy > 0) && (y +dy/1000 >  game->height()-sprite.getHeight()/2)){
        dy = 0;
        y = game->height()-sprite.getHeight()/2;
    }

    Entity::move(delta);
}

void PlayerEntity::doLogic(){
    dx=0;
    dy=0;

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

    if(trigger){
        shoot();
    }
}

void PlayerEntity::shoot(){
    if(game->getTime()-lastShot < shotInterval){
        return;
    }

    lastShot = game->getTime();

    ShotEntity *shot = new ShotEntity(game, getX(), getY()-6, polarity);
    game->getEntities().push_back(shot);

}

void PlayerEntity::draw(QPainter *painter)
{
    Entity::draw(painter);
    painter->setPen(Qt::blue);
    painter->drawRect(hitBox);


}

void PlayerEntity::collidedWith(Entity *other){
    //    if(EnemyEntity * e = dynamic_cast<EnemyEntity*>(other)){
    ////        game->notifyDeath();
    //    }
    return;
}
void PlayerEntity::setLeft(bool left)
{
    this->left = left;
//    qDebug() << "Left";
}
void PlayerEntity::setRight(bool right)
{
    this->right = right;
}
void PlayerEntity::setUp(bool up)
{
    this->up = up;
}
void PlayerEntity::setDown(bool down)
{
    this->down = down;
}
void PlayerEntity::setTrigger(bool trigger)
{
    this->trigger = trigger;
}
void PlayerEntity::setPolarize(bool polarize)
{
    this->polarize = polarize;
}






