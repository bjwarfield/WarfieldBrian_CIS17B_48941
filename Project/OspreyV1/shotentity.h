 #ifndef SHOTENTITY_H
#define SHOTENTITY_H

#include "gamewidget.h"
#include <QVector>


class ShotEntity: public Entity
{
private:
    int shotSpeed;
    bool hit;
    GameWidget *game;
    QVector<Sprite*> *frames;

public:
    ShotEntity(GameWidget *game, int x, int y, polarType polarity);
    void draw(QPainter *painter);

    // Entity interface
public:
    void move(ms delta);
    void doLogic();
    void collidedWith(Entity *other);

protected:
    polarType polarity;

    // Entity interface
};

#endif // SHOTENTITY_H
