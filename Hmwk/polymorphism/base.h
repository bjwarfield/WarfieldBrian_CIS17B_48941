#ifndef BASE_H
#define BASE_H

#include "virtual.h"

class Base: public Virtual
{
private:

public:
    //Default Constructor
    Base(int rows, int cols);

    //populate array
    void fillArray();

    //reset array
    void setArraySize(int rows, int cols);

    //deconstructor
    ~Base();

    //output array to char array w/ newline for rows
    char *toString();

protected:
    //delete array contents
    void clearArray();
};

#endif // BASE_H
