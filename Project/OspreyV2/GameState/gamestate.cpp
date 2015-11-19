#include "gamestate.h"
#include "Util/timer.h"

GameState::GameState()
{

}
QList<e_ptr> &GameState::getPlayerEntities() const
{
    return playerEntities;
}
QList<e_ptr> &GameState::getEnemyEntities() const
{
    return enemyEntities;
}
QList<e_ptr> &GameState::getPlayers() const
{
    return players;
}
QList<e_ptr> &GameState::getEffects() const
{
    return effects;
}

void GameState::notifyPlayerDeath()
{
    playerControl = false;
    playerIsAlive = false;
    respawnTimer = Timer::getTime()+2;
    controlTimer = Timer::getTime()+4;
}
bool GameState::getPlayerControl() const
{
    return playerControl;
}






