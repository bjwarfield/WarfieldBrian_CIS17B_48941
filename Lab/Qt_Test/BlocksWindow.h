/* 
 * File:   MainWindow.h
 * Author: Bee-Jay
 *
 * Created on September 26, 2015, 7:47 AM
 */

#ifndef BLOCKSWINDOW_H
#define	BLOCKSWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>

class BlocksWindow : public QWidget{
    Q_OBJECT
    
public:
    BlocksWindow();
    
    virtual ~BlocksWindow();
private:
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

#endif	/* BLOCKSWINDOW_H */

