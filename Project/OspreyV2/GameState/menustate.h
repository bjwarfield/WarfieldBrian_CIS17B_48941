#ifndef MENUSTATE_H
#define MENUSTATE_H
#include "gamestate.h"
#include "TileMap/background.h"

class MenuState:public GameState
{
public:
    MenuState(GameStateManager gsm);

    // GameState interface
public:
    void init();
    void gameUpdate(double delta);
    void gameRender(QPainter *painter);
    void keyPressed(int k);
    void keyReleased(int k);

private:

    Background b;
    QSharedPointer<Background> bg;
//    UserControlPanel ucp;
//    EntityListEditor ele;
    int currentChoice;

    QVector<QString> option;
    Sprite logo;

    void select();
};

#endif // MENUSTATE_H
