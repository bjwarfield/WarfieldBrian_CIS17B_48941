#include "enemyentity.h"
#include "shotentity.h"


int ShotEntity::getDmg() const
{
    return dmg;
}
ShotEntity::ShotEntity(GameState *game, int x, int y, polarType polarity):
Entity(x,y,":/sprites/player/polarLaser.png"),shotSpeed(1000),
  hit(false),game(game),dmg(2)
{
    this->polarity = polarity;
    type = SHOT;

    dir.ry() = -shotSpeed;

    int tileWidth = sprite->getWidth()/2;

    frames.resize(2);
    for(int i=0; i<frames.size(); i++){
        frames.data()[i] = s_ptr(
                    new Sprite(sprite->getRef(), sprite->getImage().copy(
                       tileWidth*i, 0, tileWidth, sprite->getHeight())));

    }

    sprite = frames.at(polarity);
    hitBox.setRect(getX()-sprite->getWidth()/2,
                   getY()-sprite->getHeight()/2,
                   sprite->getWidth(),
                   sprite->getHeight());

}

void ShotEntity::draw(QPainter *painter)
{
    Entity::draw(painter);
//    painter->setPen(Qt::green);
//    painter->drawRect(hitBox);
}


void ShotEntity::doLogic(double delta)
{

}

void ShotEntity::move(double delta)
{
    Entity::move(delta);


    if(getY() < -150){
        removeThis = true;
    }
}

void ShotEntity::move(double delta, float xShift)
{
    Entity::move(delta, xShift);


    if(getY() < -150){
        removeThis = true;
    }
}

void ShotEntity::move(double delta, float xShift, float yShift)
{
    Entity::move(delta, xShift, yShift);
    if(getY() < -150){
        removeThis = true;
    }
}

bool ShotEntity::getHit() const
{
    return hit;
}

void ShotEntity::collidedWith(const e_ptr &other)
{
    if(hit){
        return;
    }

    if(other->getType() == ENEMY){
        if(qSharedPointerCast<EnemyEntity>(other)->isDead()){
            return;
        }
        hit = true;
        removeThis = true;
//        qDebug()<<"Shot hit Enemy";
    }
}

ShotEntity::~ShotEntity()
{
//    qDebug()<<"Shot Destroyed: " <<x;
}




