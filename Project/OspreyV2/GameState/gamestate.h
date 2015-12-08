#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameState/gamestatemanager.h"

class GameStateManager;

class GameState
{
public:
    GameState(GameStateManager *gsm);
    virtual void init() = 0;
    virtual void gameUpdate(double delta) = 0;
    virtual void gameDraw(QPainter *painter) = 0;
    virtual void keyPressed(int k) = 0;
    virtual void keyReleased(int k) = 0;


    QList<e_ptr> &getPlayerEntities();
    QList<e_ptr> &getEnemyEntities();
    QList<e_ptr> &getPlayers();
    QList<e_ptr> &getEffects();

    void notifyPlayerDeath();

    bool getPlayerControl() const;

    virtual ~GameState();

   int height() const;
   int width() const;
   QHash<QString, bool> getKeys() const;
   int rand(int min, int max);

protected:
    GameStateManager *gsm;
    bool playerIsAlive;
    double respawnTimer;
    bool playerControl;
    double controlTimer;
    bool up, down, left, right, trigger, polarize, burst;

    //entity containers
    QList<e_ptr> playerEntities;
    QList<e_ptr> enemyEntities;
    QList<e_ptr> players;
    QList<e_ptr> effects;
    void removeDeadEntities(QList<e_ptr> &list);

};

#endif // GAMESTATE_H
