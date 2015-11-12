#include <QtWidgets>

#include "tetrisboard.h"
#include "tetriswindow.h"

//! [0]
TetrisWindow::TetrisWindow()
{
    QDesktopWidget *monitor;
    // get the size of the monitor being used.
    monitor = new QDesktopWidget();
    int screenHeight = monitor->geometry().height();
    int screenWidth = monitor->geometry().width();

    //set the main game window size according to the monitor window.
    setFixedSize(screenWidth-(screenWidth*.1),screenHeight-(screenHeight*.1));
    int windowHeight = this->size().height();
    int windowWidth = this->size().width();
    setGeometry((screenWidth - windowWidth) / 2,(screenHeight - windowHeight) / 2,windowWidth,windowHeight);

    board = new TetrisBoard;

    this->
//! [0]

    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    board->setNextPieceLabel(nextPieceLabel);

//! [1]
    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
//! [1]
    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    linesLcd = new QLCDNumber(5);
    linesLcd->setSegmentStyle(QLCDNumber::Filled);

//! [2]
    startButton = new QPushButton(tr("&Start"));
    startButton->setStyleSheet("QPushButton {background-color:blue;color:red}");
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setStyleSheet("QPushButton {background-color:blue;color:red}");
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setStyleSheet("QPushButton {background-color:blue;color:red}");
    pauseButton->setFocusPolicy(Qt::NoFocus);
//! [3] //! [4]

    connect(startButton, SIGNAL(clicked()), board, SLOT(start()));
//! [4] //! [5]
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), board, SLOT(pause()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));
    connect(board, SIGNAL(linesRemovedChanged(int)),
            linesLcd, SLOT(display(int)));
//! [5]

//! [6]

    QGridLayout *layout = new QGridLayout;

    //setup menu bar with menu and submenus
    menuBar = new QMenuBar();
    fileMenu = new QMenu("File");
    controlMenu = new QMenu("Controller");
    submenu[0] = new QAction("Open",this);
    submenu[1] = new QAction("Close",this);
    submenu[2] = new QAction("Setup",this);
    menuBar->addMenu(fileMenu);
    menuBar->addMenu(controlMenu);
    fileMenu->addAction(submenu[0]);
    fileMenu->addAction(submenu[1]);

    controlMenu->addAction(submenu[2]);
    QObject::connect(submenu[2],SIGNAL(triggered()),this,SLOT(controllerSetup()));

    layout->setMenuBar(menuBar);
    //end of menu bar

    layout->addWidget(createLabel(tr("<font color=red><font size=6>NEXT</font>")), 0, 0,1,1,0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("<font color=red><font size=6>LEVEL</font>")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(board, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("<font color=red><font size=6>SCORE</font>")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("<font color=red><font size=6>LINES REMOVED</font>")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    layout->setHorizontalSpacing(0);
    setLayout(layout);

    setStyleSheet("background-image: url(:/Images/background_new.png)");
    setWindowTitle(tr("Tetris"));


}
//! [6]

//! [7]
QLabel *TetrisWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
//! [7]
void TetrisWindow::controllerSetup()
{
    control = new Control();
}

