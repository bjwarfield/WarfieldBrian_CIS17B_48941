/*
*
* September 9th, 2015
* Template for all Windowed Creations
*/

//System Libraries
#include <QApplication>
#include <QDialog>
#include "arraydialog.h"
#include "arrayclass.h"

//User Libraries
//Global Constants
//Function Prototypes

//Execution begins here
int main(int argc, char *argv[]){
    //Start the Windowed Applications
    QApplication app(argc, argv);

    QDialog q;
    q.show();
    //Send to the controller
    return app.exec();
}
