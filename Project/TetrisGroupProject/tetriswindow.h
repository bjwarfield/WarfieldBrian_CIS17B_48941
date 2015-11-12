#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>
#include "control.h"
#include <QDesktopWidget>

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
class QMenu;
class QMenuBar;
class QAction;
QT_END_NAMESPACE
class TetrisBoard;

//! [0]
class TetrisWindow : public QWidget
{
    Q_OBJECT


public:
    TetrisWindow();

public slots:
    void controllerSetup();

private:
    QLabel *createLabel(const QString &text);
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *controlMenu;
    QAction *submenu[5];
    TetrisBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
    Control *control;

};
//! [0]

#endif
