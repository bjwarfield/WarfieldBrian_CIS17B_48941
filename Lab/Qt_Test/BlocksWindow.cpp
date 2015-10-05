/* 
 * File:   MainWindow.cpp
 * Author: Bee-Jay
 * 
 * Created on September 26, 2015, 7:47 AM
 */

#include "BlocksWindow.h"

//public construtor
BlocksWindow::BlocksWindow()
{
    board = new BlocksBoard;
    
    //score display variable
    scoreLcd = new QLCDNumber(5);
    scoreLcd-> setSegmentStyle(QLCDNumber::Filled);
    
    //game buttons
    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton -> setFocusPolicy(Qt::NoFocus);
    
    //connect button slots
    connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), app, SLOT(quit()));
    
    
    
}



//MainWindow::MainWindow(const MainWindow& orig) {
//}

BlocksWindow::~BlocksWindow() {
}

