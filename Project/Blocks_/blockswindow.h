#ifndef BLOCKSWINDOW_H
#define BLOCKSWINDOW_H




#include <QWidget>
#include <QFrame>

#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>

#include "blocksboard.h"

//namespace Ui {
//class BlocksWindow;
//}

class BlocksWindow : public QWidget
{
    Q_OBJECT

public:
    BlocksWindow();


private:
//    Ui::BlocksWindow *ui;
   QLabel *createLabel(const QString &text);

   BlocksBoard *board;
   QLabel *nextPieceLabel;
   QLCDNumber *scoreLcd;
   QLCDNumber *levelLcd;
   QLCDNumber *linesLcd;
   QPushButton *startButton;
   QPushButton *quitButton;
   QPushButton *pauseButton;


};

#endif // BLOCKSWINDOW_H
