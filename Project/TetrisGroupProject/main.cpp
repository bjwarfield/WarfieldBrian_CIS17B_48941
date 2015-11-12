#include <stdlib.h>

#include "startwindow.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   StartWindow *welcomeScreen = new StartWindow();
   welcomeScreen->show();

   return app.exec();
}
