#include "enemypestilence.h"

EnemyPestilence::EnemyPestilence(GameState *game, int x, int y, polarType polarity, Path *path, QString ref):
    EnemyEntity(game, x, y, polarity, path, ":/sprites/enemy/pestilence.png" )
{

}



void EnemyPestilence::draw(QPainter *painter)
{
}

void EnemyPestilence::doLogic(double delta)
{
}

void EnemyPestilence::collidedWith(const e_ptr &other)
{
}
