#include "base.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//constructor class
Base::Base(int rows, int cols)
    :Virtual(rows, cols)
{


    numRows = rows >= 1? rows : 1;
    numCols = cols>=1 ? cols : 1;

    fillArray();
}

//populate array
void Base::fillArray()
{
//create and initialize pseudorandom number generator
std::srand(std::time(0));

//create new array
array = new int*[numRows];

//loop through array, populating each nRow index with a new nCol, and each nCol index with a random number
for(int i = 0; i < numRows;++i){
    array[i] = new int[numCols];
    for(int j=0; j < numCols; ++j){
//                        array[i][j] = (std::rand()%127);//random number
        //           array[i][j] = 81;//q
        array[i][j] = 65 + (i*numCols)+j;//ABC...
    }
}
}


//delete currrent array then allocate and fill new one
void Base::setArraySize(int rows, int cols)
{
    clearArray();
    numRows = rows >= 1? rows : 1;
    numCols = cols>=1 ? cols : 1;
    fillArray();
}


//delete allocated memory for array
 void Base::clearArray()
 {
     for(int i = 0; i < numRows; ++i){
         delete[] array[i];
     }
     delete[] array;

 }

 //output array to char array
 char* Base::toString(){
     //create char array with length of all elements in array plus one for null terminator
     int length(numCols * numRows + numRows +1);
 //    std::cout << length << std::endl;
     char* list = new char[length];

     //loop through array, populating each int index to char array
     for(int i = 0; i < numRows; ++i){
         for(int j = 0; j < numCols; ++j){
 //            std::cout << "Index " << (i*numCols)+j << " Value: " << array[i][j] << std::endl;

             list[(i*numCols)+j+i]=array[i][j];

             if(j==(numCols-1)){
                 list[(i*numCols)+j+i+1] = '\n';
             }

         }
         list[numCols * numRows + numRows] = '\0';//null terminator
     }

//     std::cout << list;

     return list;

 }

 //deconstructor method
 Base::~Base()
 {
     clearArray();
 }
