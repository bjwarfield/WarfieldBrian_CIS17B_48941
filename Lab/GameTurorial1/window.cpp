#include "window.h"


#include <QGridLayout>

Window::Window()
{
    setWindowTitle("Osprey Assault");

    gw = new GameWidget(this);

    QGridLayout *layout =  new QGridLayout;

    layout->addWidget(gw,0,0);
    setLayout(layout);
    show();
}

