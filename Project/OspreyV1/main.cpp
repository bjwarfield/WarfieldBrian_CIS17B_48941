#include <QApplication>
#include <QSurfaceFormat>
#include <QtCore>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QSurfaceFormat fmt;
//    fmt.setSamples(4);
//    QSurfaceFormat::setDefaultFormat(fmt);


    Window window;


    window.gw->gameLoop();



    return a.exec();
}
