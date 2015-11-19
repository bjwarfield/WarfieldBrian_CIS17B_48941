#include "gamestatemanager.h"

GameStateManager::GameStateManager()
{
    gameStates.append(gs_ptr(new MenuState(this)));
    gameStates.append(gs_ptr(new Level1State(this)));
    currentState = MENUSTATE;
}

GameStateManager::setState(GameStateManager::state s)
{
    gameStates.at(s)->init();
    currentState = s;
}

Qlist<gs_ptr> &GameStateManager::getGateStates()
{
    return gameStates;
}

GameStateManager::gameUpdate(double delta)
{
    gameStates.at(currentState)->gameUpdate(delta);
}

GameStateManager::gameRender(QPainter *painter)
{
    gameStates.at(currentState)->gameRender(painter);
}

GameStateManager::keyPressed(int k)
{
    gameStates.at(currentState)->keyPressed(k);
}

GameStateManager::keyReleased(int k)
{
    gameStates.at(currentState)->keyReleased(k);
}



