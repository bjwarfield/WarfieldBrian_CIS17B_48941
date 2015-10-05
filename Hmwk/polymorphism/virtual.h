#ifndef VIRTUAL_H
#define VIRTUAL_H


class Virtual
{

protected:
    //constructor prototype
    Virtual(int, int);

    //array height
    int numRows;

    //array width
    int numCols;

    //2d array
    int ** array;


public:

    //populate array function prototype
    virtual void fillArray()=0;

};

#endif // VIRTUAL_H
