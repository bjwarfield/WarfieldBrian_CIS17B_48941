#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <QPainter>
#include <QSharedPointer>


typedef QSharedPointer<GameState*> gs_ptr;
class GameStateManager
{
private:
    state currentState;
    QList<gs_ptr> gameStates;

public:
    static enum state {MENUSTATE, LEVEL1STATE}

    GameStateManager();

    setState(state s);
    Qlist<gs_ptr> &getGateStates();
    gameUpdate(double delta);
    gameRender(QPainter *painter);
    keyPressed(int k);
    keyReleased(int k);


};

#endif // GAMESTATEMANAGER_H
