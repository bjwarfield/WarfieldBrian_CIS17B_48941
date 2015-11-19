#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gamestatemanager.h"



class GameState
{
public:
    GameState();
    virtual void init() = 0;
    virtual void gameUpdate(double delta) = 0;
    virtual void gameRender(QPainter *painter) = 0;
    virtual void keyPressed(int k);
    virtual void keyReleased(int k);


    QList<e_ptr> &getPlayerEntities() const;
    QList<e_ptr> &getEnemyEntities() const;
    QList<e_ptr> &getPlayers() const;
    QList<e_ptr> &getEffects() const;

    void notifyPlayerDeath();

    bool getPlayerControl() const;

protected:
    GameStateManager gsm;
    bool playerIsAlive;
    double respawnTimer;
    bool playerControl;
    double controlTimer;
    bool up, down, left, right, trigger, polarize, burst;

    //entity containers
    const QList<e_ptr> playerEntities;
    const QList<e_ptr> enemyEntities;
    const QList<e_ptr> players;
    const QList<e_ptr> effects;

};

#endif // GAMESTATE_H
