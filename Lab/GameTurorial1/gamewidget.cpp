
#include "gamewidget.h"

#include <QLayout>
#include <QPainter>
#include <QThread>
#include <QDebug>
#include <QPaintEvent>


GameWidget::GameWidget(QWidget *parent):
    QWidget(parent),
    gameRunning(true), FPS(60), TARGETTIME(1000/FPS)
{

    setFixedSize(WIDTH, HEIGHT);
    setFocusPolicy(Qt::StrongFocus);

    eTimer.start();

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

        update();


        ms sleepTime = TARGETTIME - delta/1000;
        QThread::msleep(sleepTime);

        totalTime += getTime() - lastLoopTime;
        frameCount++;
        if(frameCount ==maxFrameCount){
            qDebug()<<"Average FPS: "<<static_cast<float>(1000.0 / (totalTime/frameCount));
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

    painter.fillRect(e->rect(),QBrush(QColor(64, 32, 64)));
//    painter.fillRect(0,0,WIDTH,HEIGHT,QBrush(Qt::black,Qt::SolidPattern));
//    painter.drawText(WIDTH/2,HEIGHT/2,"Test");

    painter.end();
}
