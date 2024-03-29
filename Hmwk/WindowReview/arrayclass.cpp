#include "arrayclass.h"
#include <random>
#include <iostream>



/*
 *constructor method
 * @param nRows number of rows
 * @param nCols number of columns
*/
ArrayClass::ArrayClass(int nRows = 1, int nCols = 1){
    if(nRows >= 1 && nCols >= 1){
        this->nRows = nRows;
        this->nCols = nCols;
    }else{
        //assign default values if input is less than 1
        this->nCols=1;
        this->nRows=1;
    }

    init();

}

//build and populate 2d array
void ArrayClass::init(){

    //create and initialize pseudorandom number generator
    std::random_device rd;
    std::mt19937 random(rd());

    //create new array
    array = new int*[nRows];

    //loop through array, populating each nRow index with a new nCol, and each nCol index with a random number
    for(int i = 0; i < nRows;++i){
        array[i] = new int[nCols];
        for(int j=0; j < nCols; ++j){
//                        array[i][j] = (random()%127);//random number
            //           array[i][j] = 81;//q
            array[i][j] = 65 + (i*nCols)+j;//ABC...
        }
    }
}

//output array to char array
char* ArrayClass::toString(){
    //create char array with length of all elements in array plus one for null terminator
    int length(nCols * nRows+1);
//    std::cout << length << std::endl;
    char* list = new char[length];

    //loop through array, populating each int index to char array
    for(int i = 0; i < nRows; ++i){
        for(int j = 0; j < nCols; ++j){
//            std::cout << "Index " << (i*nCols)+j << " Value: " << array[i][j] << std::endl;

            list[(i*nCols)+j]=array[i][j];

        }
        list[nCols * nRows] = '\0';//null terminator
    }

    return list;

}

ArrayClass::~ArrayClass(){
    for(int i = 0; i < nRows; ++i){
        delete[] array[i];
    }
    delete[] array;
}

