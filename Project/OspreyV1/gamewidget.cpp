
#include "gamewidget.h"
#include "playerentity.h"


#include <QLayout>
#include <QPainter>
#include <QThread>
#include <QDebug>
#include <QPaintEvent>
#include <QtCore>


GameWidget::GameWidget(QWidget *parent):
    QWidget(parent),
    gameRunning(true), FPS(60), TARGETTIME(1000/FPS), pressCount(1),
    waitingForKeyPressed(true),message("")
{


    setFixedSize(WIDTH, HEIGHT);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    initEntities();

    eTimer.start();


}

void GameWidget::initEntities(){
    ship = new PlayerEntity(this, WIDTH/2, HEIGHT-100);

    entities << ship;
}


void GameWidget::removeEntity(Entity *entity)
{
    removeList << entity;
}

QList<Entity*>& GameWidget::getEntities(){
  return entities;
}

void GameWidget::notifyDeath(){
    message = "You have Died!";
    ship->setHorizontalMovement(0);
    ship->setVerticalMovement(0);
    waitingForKeyPressed = true;
}

void GameWidget::trigger()
{

}

void GameWidget::startGame(){
    entities.clear();
    initEntities();
}

void GameWidget::gameLoop()
{
    ms lastLoopTime;
    lastLoopTime = getTime();

    ms delta = 0;

    ms totalTime = 0;
    int frameCount = 0;
    int maxFrameCount = FPS;

    while(gameRunning){
        delta = getTime() - lastLoopTime;
        lastLoopTime = getTime();
        qApp->processEvents();

        if(!waitingForKeyPressed){
            for(int i = 0; i < entities.size(); i++){
                Entity * entity = entities[i];
                entity->doLogic();
                entity->move(delta);
            }


            for (int p = 0; p < entities.size(); p++){
                for (int s = p+1; s< entities.size(); s++){
                    Entity * e1 = entities.at(p);
                    Entity * e2 = entities.at(s);

                    if(e1->collidesWith(e2)){
                        e1->collidedWith(e2);
                        e2->collidedWith(e1);
                    }
                }

            }

//            for(int r = 0; r < removeList.size(); r++){
//                int rIndex = entities.indexOf(removeList.at(r));
//                if(rIndex != -1){
//                    Entity * temp = entities.takeAt(rIndex);
//                    delete temp;
//                }

//            }

            QList<Entity *>::iterator it;

            for(it = removeList.begin(); it != removeList.end(); ++it){
                int idx = entities.indexOf(*it);
                if(idx >= 0){
                    delete entities.takeAt(idx);
                }
            }
            removeList.clear();
        }

        update();
        ms sleepTime = TARGETTIME - delta/1000;
        QThread::msleep(sleepTime);

        totalTime += getTime() - lastLoopTime;
        frameCount++;
        if(frameCount ==maxFrameCount){
            averageFPS=static_cast<float>(1000.0 / (totalTime/frameCount));
            qDebug()<<"Average FPS: "<<averageFPS;
            frameCount = 0;
            totalTime = 0;
        }
    }
}

void GameWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(e->rect(),QBrush(QColor(45, 10, 56)));

    if(!waitingForKeyPressed){
        for(int i = 0; i < entities.size(); i++){
            Entity * entity = entities.at(i);

            entity->draw(&painter);
//            qDebug() << "Entity Size: " <<entities.size();
        }

        painter.setPen(Qt::red);
        painter.drawText(15,15, "Average FPS: " + QString::number(averageFPS));
        painter.drawText(15,30, "Entities: " + QString::number(entities.size()));

    }else{
        painter.drawText((WIDTH - painter.fontMetrics().width(message))/2,
                         HEIGHT/2, message);

        painter.drawText((WIDTH - painter.fontMetrics()
                          .width("W, A, S, D, for controls, Space to fire"))/2,
                         static_cast<int>(HEIGHT * 0.55),
                         "W, A, S, D, for controls, Space to fire");

    }

    painter.end();
}

void GameWidget::keyPressEvent(QKeyEvent * k){
    if(k->isAutoRepeat()){
        return;
    }
    if(waitingForKeyPressed){
        QWidget::keyPressEvent(k);
        return;
    }

    switch (k->key()) {
    case Qt::Key_A:
        ship->setLeft(true);
        break;
    case Qt::Key_D:
        ship->setRight(true);
        break;
    case Qt::Key_W:
        ship->setUp( true);
        break;
    case Qt::Key_S:
        ship->setDown(true);
        break;
    case Qt::Key_Space:
        ship->setTrigger(true);
        break;

    default:
        QWidget::keyPressEvent(k);
        break;
    }
}

void GameWidget::keyReleaseEvent(QKeyEvent *k){
    if(k->isAutoRepeat()){
        return;
    }
    if(!waitingForKeyPressed){
        switch (k->key()) {
        case Qt::Key_A:
            ship->setLeft(false);
            break;
        case Qt::Key_D:
            ship->setRight(false);
            break;
        case Qt::Key_W:
            ship->setUp(false);
            break;
        case Qt::Key_S:
            ship->setDown(false);
            break;
        case Qt::Key_Space:
            ship->setTrigger(false);
            break;

        default:
            QWidget::keyReleaseEvent(k);
            break;
        }
    }else{
        if(pressCount == 1){
            waitingForKeyPressed = false;
            startGame();
            pressCount = 0;
        }else{
            pressCount ++;
        }
    }
}

