#ifndef BLOCKSBOARD_H
#define BLOCKSBOARD_H

#include "blockspiece.h"

#include <QBasicTimer>
#include <QFrame>
#include <QLabel>
#include <QPointer>



class BlocksBoard: public QFrame
{
    Q_OBJECT

public:
    BlocksBoard(QWidget *parent = 0);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const;
    QSize minimunSizeHint() const;

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    enum {BoardWidth = 10, BoardHeight = 22};

    BlockShape &shapeAt(int x, int y);
    int timeoutTime();
    int squareWidth();
    int squareHeight();
    void clearBoard();
    void dropDown();
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void removeFullLines();
    void newPiece();
    void showNextPiece();
    bool tryMove(const BlocksPiece &newPiece, int newX, int newY);
    void drawSquare(QPainter &painter, int x, int y, BlockShape shape);

    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted;
    bool isPaused;
    bool isWaitingAfterLine;
    BlocksPiece curPiece;
    BlocksPiece nextPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    int numPiecesDropped;
    int score;
    int level;
    BlockShape board[BoardHeight * BoardWidth];


 };

#endif // BLOCKSBOARD_H
