#ifndef ARRAYCLASS_H
#define ARRAYCLASS_H


class ArrayClass
{
private:
    //array height
    int nRows;

    //array width
    int nCols;

    //2d array
    int **array;

    //populate Array with random 2 digit integers
    void init();

public:
    //constructor method
    ArrayClass(int nRows, int nCols);

    //output array to string
    char * toString();

    //deconstructor method
    ~ArrayClass();


};

#endif // ARRAYCLASS_H
