#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H
#include <QtMath>
#include <QVector>
#include "entity.h"
#include "Main/gamewidget.h"
#include "GameState/gamestate.h"

class GameState;
enum throttle{OFF, FULL, TURBO};
class PlayerEntity:public Entity
{
public:
    PlayerEntity(GameState *game, int x, int y);
    void move(double delta)Q_DECL_OVERRIDE;

    void doLogic(double delta)Q_DECL_OVERRIDE;
    void draw(QPainter * painter)Q_DECL_OVERRIDE;

    void collidedWith(const e_ptr &other)Q_DECL_OVERRIDE;

    ~PlayerEntity();

    int getEnergy() const;
    void setFlinching(double flinchTime);
    void setThrottleSetting(const throttle &value);

private:
    GameState *game;

    QVector<s_ptr> thrusterframes;
    QVector<s_ptr> flashFrames;

    //control variables
    bool left;
    bool right;
    bool up;
    bool down;
    bool trigger;
    bool polarize;
    bool burst;
    bool polarKeyLock;

    bool flinching;
    double flinchTimer;

    int moveSpeed;
    const float DIAGONAL;

    int haloSize;
    double lastShot;
    double shotInterval;

    int energy;
    throttle throttleSetting;
    QRadialGradient whiteAura;
    QRadialGradient blackAura;


    void shoot();
    void shootBurst();
    void polarSwap();
};

#endif // PLAYERENTITY_H
