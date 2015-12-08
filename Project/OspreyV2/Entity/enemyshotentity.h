#ifndef ENEMYSHOTENTITY_H
#define ENEMYSHOTENTITY_H

#include "entity.h"
#include "Main/gamewidget.h"
class EnemyShotEntity: public Entity
{
public:
    EnemyShotEntity(GameState *game, int x, int y, polarType polarity = WHITE);

    // Entity interface
public:
    void draw(QPainter *painter)Q_DECL_OVERRIDE;
    void doLogic(double delta)Q_DECL_OVERRIDE;
    void collidedWith(const e_ptr &other)Q_DECL_OVERRIDE;
    ~EnemyShotEntity();

protected:
    GameState *game;
    bool hit;

};

#endif // ENEMYSHOTENTITY_H
