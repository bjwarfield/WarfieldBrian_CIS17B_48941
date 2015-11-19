#include "menustate.h"
#include "Main/gamewidget.h"

MenuState::MenuState(GameStateManager gsm):
    logo(":/title/osprey-logo.png")
{
    this->gsm = gsm;

    currentChoice = 0;

    option.resize(4);
    option[0] = "Start";
    option[1] = "User Control Panel";
    option[2] = "Level Editor";
    option[3] = "Quit";

    bg = QSharedPointer<Background>(new Background(":/backgrounds/clouds_01.png", 1.2));
    bg->setMovement(-30,10);
    init();

}



void MenuState::init()
{

}

void MenuState::gameUpdate(double delta)
{
    bg->gameUpdate(delta);

}

void MenuState::gameRender(QPainter *painter)
{
    bg->gameRender(painter);
    logo.draw(painter, (GameWidget::WIDTH - logo.getWidth())/2, 75);

    for(int i = 0; i < option.size(); i++){
        QString s = option.at(i);
        if(i == currentChoice){
            painter->setPen(Qt::red);
        }else{
            painter->setPen(Qt::gray);
        }
        painter->font().setPointSize(34);

        painter->drawText((GameWidget::WIDTH - QFontMetrics::width(s))/2,340 + i * 45);

    }


}

void MenuState::keyPressed(int k)
{
}

void MenuState::keyReleased(int k)
{
}

void MenuState::select()
{
    switch(currentChoice){
    case 0:
        //start game
        gsm.setState(GameStateManager::LEVEL1STATE);
        break;
    case 1:
        //TODO User Control Panel
        break;
    case 2:
        //TODO Level Editor
        break;
    case 3:
        GameWidget.
        break;
    }
}
