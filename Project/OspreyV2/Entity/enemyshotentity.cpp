#include "enemyshotentity.h"

EnemyShotEntity::EnemyShotEntity(GameState *game, int x, int y, polarType polarity):
    Entity(x,y,":/sprites/enemy/enemyShot.png"), game(game),
    hit(false)
{
    this->polarity = polarity;
    type = ENEMYSHOT;

    int tileHeight = sprite->getHeight()/2;

    frames.resize(2);

    for(int i = 0; i < frames.size(); i++){
        frames.data()[i] = s_ptr(new Sprite(
                    sprite->getRef(), sprite->getImage().copy(
                        0, tileHeight*i, sprite->getWidth(), tileHeight)));
    }

    sprite = frames.at(this->polarity);
}



void EnemyShotEntity::draw(QPainter *painter)
{
    Entity::draw(painter);
}

void EnemyShotEntity::doLogic(double delta)
{
    if(getY() < -50 || getY() > game->height()+50 || getX() < -50 || getX() > game->width()+50 ){
        removeThis = true;
    }
}

void EnemyShotEntity::collidedWith(const e_ptr &other)
{
    if(hit){
        return;
    }
    if(other->getType() == PLAYER){
        hit = true;
        removeThis = true;
    }

}

EnemyShotEntity::~EnemyShotEntity()
{

}
