#ifndef LEVEL1STATE_H
#define LEVEL1STATE_H

#include "GameState/gamestate.h"

#include <TileMap/tilemap.h>


class Level1State:public GameState
{
private:
    QSharedPointer<TileMap> tilemap;

    double timeStart;
    QVector<bool> events;
    bool levelEnd;
    double eventTimer;
    void moveEntities(double delta);
    void checkCollisions();

    //debug stuff
    bool spawn;
    bool enemyTrigger;
    void spawnEnemy();

public:
    Level1State(GameStateManager *gsm);

    ~Level1State();
    // GameState interface
public:
    void init();
    void gameUpdate(double delta);
    void gameDraw(QPainter *painter);
    void keyPressed(int k);
    void keyReleased(int k);
};

#endif // LEVEL1STATE_H
