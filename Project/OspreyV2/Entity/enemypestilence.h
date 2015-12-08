#ifndef ENEMYPESTILENCE_H
#define ENEMYPESTILENCE_H

#include "Entity/enemyentity.h"



class EnemyPestilence:public EnemyEntity
{
public:
    EnemyPestilence(GameState *game, int x, int y, polarType polarity, Path *path, QString ref);

    // Entity interface
public:
    void draw(QPainter *painter);
    void doLogic(double delta);
    void collidedWith(const e_ptr &other);
};

#endif // ENEMYPESTILENCE_H
