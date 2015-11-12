#include "shotentity.h"

ShotEntity::ShotEntity(GameWidget *game, int x, int y, polarType polarity):
Entity(x,y,":/resources/sprites/player/polarLaser.png"),shotSpeed(1000),
  hit(false),game(game), polarity(polarity)
{
    dy = -shotSpeed;

    int tileWidth = sprite.getWidth()/2;

    frames = new QVector<Sprite*>(2);
    for(int i=0; i<frames->size(); i++){
        frames->data()[i] = new Sprite(sprite.getRef(), sprite.getImage().copy(
                       tileWidth*i, 0, tileWidth, sprite.getHeight()));

    }

}

void ShotEntity::draw(QPainter *painter)
{
    frames->at(polarity)->draw(painter, getX(), getY());
}

void ShotEntity::move(ms delta)
{
    Entity::move(delta);

    if(y < -150){
        game->removeEntity(this);
    }
}

void ShotEntity::doLogic()
{

}

void ShotEntity::collidedWith(Entity *other)
{
    if(hit){
        return;
    }
    return;
}




