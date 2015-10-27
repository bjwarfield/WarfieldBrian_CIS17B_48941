/*
 * File:   main.cpp
 * Author: Bee-Jay
 *
 * Created on October 20, 2015, 4:06 PM
 */

#include <QApplication>
#include "HelloForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    HelloForm form;
    form.show();
    
    return app.exec();
}
