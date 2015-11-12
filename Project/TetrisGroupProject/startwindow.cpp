#include "startwindow.h"
#include "tetriswindow.h"
#include <QtWidgets>

#include <stdlib.h>

StartWindow::StartWindow(QWidget *parent) : QWidget(parent)
{    
    // get the size of the monitor being used.
    monitor = new QDesktopWidget();
    int screenHeight = monitor->geometry().height();
    int screenWidth = monitor->geometry().width();

    //set the main game window size according to the monitor window.
//    setFixedSize(screenWidth-(screenWidth*.55),screenHeight-(screenHeight*.1));
    int windowHeight = this->size().height();
    int windowWidth = this->size().width();
//    setGeometry((screenWidth - windowWidth) / 2,(screenHeight - windowHeight) / 2,windowWidth,windowHeight);

    backGround = new QPixmap(":/Images/startbackground.png");

    backGroundLabel = new QLabel();
    int w = backGroundLabel->width();
    int h = backGroundLabel->height();
    backGroundLabel->setPixmap(backGround->scaled(w,h,Qt::KeepAspectRatio));

    startButton = new QPushButton("Start");
    boxLayout = new QVBoxLayout();

    boxLayout->addWidget(backGroundLabel);

    boxLayout->addWidget(startButton);
    QObject::connect(startButton,SIGNAL(clicked()),this,SLOT(gameStart()));

    setLayout(boxLayout);
    setWindowTitle("TETRIS");

    //setGeometry(372,35,0,0);
    //setFixedSize(620,650);

}


void StartWindow::gameStart()
{
    close();
    TetrisWindow *window = new TetrisWindow();
    window->show();
}


