#include <iostream>
#include <arrayclass.h>

using namespace std;


int main()
{
    int arrayHeight;
    int arrayWidth;

    //get input from user
    cout << "Enter array height: ";
    cin >> arrayHeight;
    cout << "\nEnter array width: ";
    cin >> arrayWidth;
    cout << "\n";

    //instantiate and initialize ArrayClass
    ArrayClass* array = new ArrayClass(arrayHeight,arrayWidth);

    //get class array as string (char array)
    char* string =  array->toString();

    //output to console, formatted by height and width
    for(int i = 0; i < (arrayHeight * arrayWidth); ++i){
        cout << string[i];
        if((i+1) % arrayWidth == 0){
            cout << '\n';
        }

    }
    cout << '\n';

    //destroy object
    array->~ArrayClass();

    //exit program
    return 0;
}

