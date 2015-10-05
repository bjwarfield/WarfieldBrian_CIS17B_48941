#include "blocksboard.h"
#include <QtGui>


//class constructor (qframe widget)
BlocksBoard::BlocksBoard(QWidget *parent)
    :QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    isStarted = false;
    isPaused = false;
    clearBoard();

    nextPiece.setRandomShape();
}

//assign nexPieceLabel with constructed label
void BlocksBoard::setNextPieceLabel(QLabel *label)
{
    nextPieceLabel = label;
}

//set size hints based on frame size
QSize BlocksBoard::sizeHint() const
{
    return QSize(BoardWidth * 15 + frameWidth() *2,
                 BoardHeight * 15 + frameWidth()*2 );

}

//minimum size hint
QSize BlocksBoard::minimunSizeHint() const
{
    return QSize (BoardWidth * 5 + frameWidth() * 2,
                  BoardHeight * 5 + frameWidth() *2);

}


//initialize and start game
void BlocksBoard::start()
{
    if(isPaused){//do nothing if game is paused
        return;
    }

    isStarted = true;//set started to true
    isWaitingAfterLine = false;//set waiting to false

    //reset score values and clear board
    numLinesRemoved = 0;
    numPiecesDropped = 0;
    score = 0;
    level = 1;
    clearBoard();

    //emit signals
    emit linesRemovedChanged(numLinesRemoved);
    emit scoreChanged(score);
    emit levelChanged(level);

    //create new piece
    newPiece();

    //start timer
    timer.start(timeoutTime(), this);


}

//pause the game
void BlocksBoard::pause()
{
    //do nothinf if game hant started yet
    if(!isStarted){
        return;
    }

    //inverser pause status (True to false: False to True)
    isPaused = !isPaused;


    if(isPaused){
        timer.stop();//stop timer if paused
    }else{
        timer.start(timeoutTime(), this);//continue timer if unpaused
    }
    update();
}



//paint board and board contents
void BlocksBoard::paintEvent(QPaintEvent *event)
{
   //pass event to parent class
    QFrame::paintEvent(event);

    //instantiate painter object
    QPainter painter(this);
    QRect rect = contentsRect();

    //show pause text if paused
    if(isPaused){
        painter.drawText(rect, Qt::AlignCenter, tr("Pause"));
        return;
    }

    //determine top of board by subtracting the BoardHeight from the bottom coordinate
    int boardTop = rect.bottom() - BoardHeight*squareHeight();

    //draw blocks on the board
    for (int i = 0; i < BoardHeight; ++i) {//for each row
        for (int j = 0; j < BoardWidth; ++j) {//for each col
            BlockShape shape = shapeAt(j, BoardHeight - i - 1);//check cell contents
            if (shape != NoShape){//if cell is not empty            {
                drawSquare(painter, rect.left() + j * squareWidth(),
                           boardTop + i * squareHeight(), shape);
            }//draw square in cell
        }
    }

    //draw current piece
    if(curPiece.shape() != NoShape){
        for (int i = 0; i< 4; ++i){
            int x = curX + curPiece.x(i);
            int y = curY + curPiece.y(i);
            drawSquare(painter, rect.left() + x* squareWidth(),
                       boardTop + (BoardHeight - y - 1) * squareHeight(),
                       curPiece.shape());//draw each peice cell
        }
    }

}


//key event handling
void BlocksBoard::keyPressEvent(QKeyEvent *event)
{
    if(!isStarted || isPaused || curPiece.shape() == NoShape){
        QFrame::keyPressEvent(event);
        return;
    }

    switch(event->key()){
    case Qt::Key_Left:
        tryMove(curPiece, curX -1, curY);
        break;
    case Qt::Key_Right:
        tryMove(curPiece, curX +1, curY);
        break;
    case Qt::Key_Down:
        tryMove(curPiece.rotatedRight(), curX, curY);
        break;
    case Qt::Key_Up:
        tryMove(curPiece.rotatedLeft(), curX, curY);
        break;
    case Qt::Key_Space:
        dropDown();
        break;
    case Qt::Key_D:
        oneLineDown();
        break;
    default:
        QFrame::keyPressEvent(event);
    }

}

//timer event handler
void BlocksBoard::timerEvent(QTimerEvent *event){

    if(event->timerId() == timer.timerId()){
        if (isWaitingAfterLine){
            isWaitingAfterLine = false;
            newPiece();
            timer.start(timeoutTime(), this);
        }else{
            oneLineDown();
        }
    }else{
        QFrame::timerEvent(event);
    }
}


//return shape at board coordinate
BlockShape & BlocksBoard::shapeAt(int x, int y)
{
    return board[(y * BoardWidth) + x];
}


//return time till next timerEvent
int BlocksBoard::timeoutTime()
{
    return 1000/ (1+level);
}

//return square width
int BlocksBoard::squareWidth(){
    return contentsRect().width() / BoardWidth;
}

//return square height
int BlocksBoard::squareHeight()
{
    return contentsRect().height() / BoardHeight;
}

//clear board grid
void BlocksBoard::clearBoard()
{
    for (int i = 0; i < BoardHeight; ++i){
        board[i] = NoShape;
    }
}

//drop current piece down
void BlocksBoard::dropDown()
{
    int dropHeight = 0;
    int newY = curY;
    while (newY > 0){
        if (!tryMove(curPiece, curX, newY - 1)){
            break;
        }

        --newY;
        ++dropHeight;

    }
    pieceDropped(dropHeight);
}

//move current piece down one line
void BlocksBoard::oneLineDown()
{
    if(!tryMove(curPiece, curX, curY -1)){
        pieceDropped(0);
    }
}

void BlocksBoard::pieceDropped(int dropHeight)
{
    for (int i = 0; i < 4; ++i){
        int x = curX + curPiece.x(i);
        int y = curY - curPiece.y(i);
        shapeAt (x,y) = curPiece.shape();

    }

    ++numPiecesDropped;
    if(numPiecesDropped % 25 == 0){
        ++level;
        timer.start(timeoutTime(), this);
        emit levelChanged(level);
    }

    score += dropHeight +7;
    emit scoreChanged(score);
    removeFullLines();

    if(!isWaitingAfterLine){
        newPiece();
    }
}


//scan board grid and remove full lines
void BlocksBoard::removeFullLines()
{
    int numFullLines = 0;//line counter

    for (int i= BoardHeight -1; i >=0; --i){//for each row
        bool lineIsFull = true;//set flag

        for (int j = 0; j< BoardWidth; ++j){//for eash cell in row
            if (shapeAt(j,i)  == NoShape){//if cell is empty
                lineIsFull = false;//clear flag
                break;//break loop
            }
        }


        if(lineIsFull){//in line is full
            ++numFullLines; //increment full lines
            for( int j = i; j < BoardHeight - 1; ++j){//for each row starting at active row
                for(int k = 0; k < BoardWidth -1; ++k){//for cell in row
                    shapeAt(k, j) = shapeAt(k, j+1); //copy row above to active row
                }
            }
            for (int j= 0; j < BoardWidth; ++j){//for each column
                shapeAt(j, BoardHeight - 1) = NoShape;//clear cell
            }
        }

        if(numFullLines > 0){//if any lines are are removed
            numLinesRemoved += numFullLines;
            score += 10 * numFullLines;
            if (numFullLines == 4){//if max lines removed
                score += 60;//bonus points
            }

            //emit signals
            emit linesRemovedChanged(numLinesRemoved);
            emit scoreChanged(score);

            timer.start(500, this);
            isWaitingAfterLine = true;
            curPiece.setShape(NoShape);
            update();
        }
    }
}

//cycle next peice to current peice and generate new piece
void BlocksBoard::newPiece()
{
    curPiece = nextPiece;
    nextPiece.setRandomShape();
    showNextPiece();
    curX = BoardWidth/2+1;
    curY = BoardHeight -1 + curPiece.minY();
    
    if(!tryMove(curPiece, curX, curY)){//if grid is full
        curPiece.setShape(NoShape);//end game
        timer.stop();
        isStarted = false;
    }
}

//update label for next piece
void BlocksBoard::showNextPiece()
{
    if(!nextPieceLabel){
        return;
    }
    
    int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    int dy = nextPiece.maxY() - nextPiece.minY() + 1;
    
    QPixmap pixMap (dx * squareWidth(), dy * squareHeight());
    QPainter painter(&pixMap);
    painter.fillRect(pixMap.rect(),nextPieceLabel->palette().background());
    
    
    for(int i = 0; i< 4; ++i ){
        int x = nextPiece.x(i) - nextPiece.minX() + 1;
        int y = nextPiece.y(i) - nextPiece.minY() + 1;
        drawSquare(painter, x* squareWidth() , y * squareHeight(), nextPiece.shape());
    }
    nextPieceLabel->setPixmap(pixMap);

}

//attempt to move peice.
//return true if successfull, false if not
bool BlocksBoard::tryMove(const BlocksPiece &newPiece, int newX, int newY)
{
    for(int i = 0; i < 4; ++i){
        int x= newX + newPiece.x(i);
        int y = newY + newPiece.y(i);

        if(x<0 || x >= BoardWidth || y < 0 || y <= BoardHeight) return false;//false if out of bounds

        if (shapeAt( x,y) !=NoShape) return false;//false if candidate cell is occupied


    }
    //if all candidate cells are clear (NoShape)
    curPiece = newPiece;
    curX = newX;
    curY = newY;
    update();
    return true;
}

//draw blocks on the grid
void BlocksBoard::drawSquare(QPainter &painter, int x, int y, BlockShape shape)
{
    static const QRgb colorTable[8] = {
        0x000000,
        0xCC6666,
        0x66CC66,
        0x6666CC,
        0xCCCC66,
        0xCC66CC,
        0x66CCCC,
        0xDAAA00

    };

    QColor color = colorTable[shape];//set color according to shape
    painter.fillRect(x+1, y+1, squareWidth() - 2, squareHeight() -2, color);

    painter.setPen(color.light());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidth() - 1, y);

    painter.setPen(color.dark());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidth() - 1, y + squareHeight() - 1,
                     x + squareWidth() - 1, y + 1);
}
