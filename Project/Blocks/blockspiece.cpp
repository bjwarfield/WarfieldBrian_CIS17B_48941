#include "blockspiece.h"
#include <stdlib.h>
#include <QtCore>


///set random piece shape (Enum value 1-7)
void BlocksPiece::setRandomShape()
{
    setShape(BlockShape(qrand() % 7 +1));
}

//return piece shape (Enum value 0-7)
BlockShape BlocksPiece::shape() const {
    return pieceShape;
}

//get x coordinate
int BlocksPiece::x(int index) const
{
    return coords[index][0];
}

//get y coordinate
int BlocksPiece::y(int index) const
{
    return coords[index][1];
}

//set x coordinate
void BlocksPiece::setX(int index, int x)
{
    coords[index][0] = x;
}

//set y coordinate
void BlocksPiece::setY(int index, int y)
{
    coords[index][1] = y;
}

//set coordinates according to block shape
void BlocksPiece::setShape(BlockShape shape){
    static const int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },//[0]NoShape
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } },//[1]ZShape
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },//[2]SShape
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },//[3]LineShape
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },//[4]TShape
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },//[5]SquareShape
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },//[6]LShape
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }//[7]RShape
    };

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
            coords[i][j] = coordsTable[shape][i][j];
        }

    }
    pieceShape = shape;
}

//return minimun x coordinate
int BlocksPiece::minX() const
{
    int min = coords[0][0];

    for (int i = 0; i < 4; ++i){
        min = qMin(min, coords[i][0]);
    }

    return min;
}

//return maximum x coordinate
int BlocksPiece::maxX() const
{
    int max = coords[0][0];

    for(int i = 1; i < 4; ++i){
        max = qMax(max, coords[i][0]);
    }
    return max;
}

//return minimun y coordinate
int BlocksPiece::minY() const
{
    int min = coords [0][1];

    for(int i = 0; i< 4; ++i){
        min = qMin(min, coords[i][1]);
    }

    return min;
}


//return maxumun y coordinate
int BlocksPiece::maxY() const
{
    int max = coords[0][1];

    for(int i = 1; i < 4; ++i){
        max = qMax(max, coords[i][1]);
    }
    return max;
}


//rotate block piece left
BlocksPiece BlocksPiece::rotatedLeft() const
{
    if (pieceShape == SquareShape){
        return *this;
    }

    BlocksPiece result;

    result.pieceShape = pieceShape;

    for (int i = 0; i< 4; ++i){
        result.setX(i, y(i));
        result.setY(i,-x(i));
    }

    return result;

}

//rotate block piece right
BlocksPiece BlocksPiece::rotatedRight() const
{
    if (pieceShape == SquareShape){
        return *this;
    }

    BlocksPiece result;

    result.pieceShape = pieceShape;
    for(int i= 0; i< 4; ++i){
        result.setX(i, -y(i));
        result.setY(i,x(i));
    }
    return result;

}
