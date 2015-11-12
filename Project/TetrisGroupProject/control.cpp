#include "control.h"

Control::Control(QWidget *parent) : QWidget(parent)
{
    dropButton = new QPushButton("DROP");
    QObject::connect(dropButton,SIGNAL(clicked()),this,SLOT(dropControl()));

    //QString *name = new QString("hello");
    //dropButton->setText("DROP: " + *name);
    dropButton->setText("DROP: ");
    leftButton = new QPushButton("LEFT");
    rightButton = new QPushButton("RIGHT");
    swapButton = new QPushButton("ROTATE");

    layout = new QGridLayout();
    vboxLayout = new QVBoxLayout();
    hboxLayout = new QHBoxLayout();


    vboxLayout->addWidget(dropButton);
    vboxLayout->addSpacing(50);
    vboxLayout->addWidget(swapButton);
    hboxLayout->addWidget(leftButton);
    hboxLayout->addSpacing(50);
    hboxLayout->addWidget(rightButton);


    layout->addLayout(vboxLayout,1,1,1,1,0);
    layout->addLayout(hboxLayout,1,1,1,1,0);

    setWindowTitle("Controller");
    setFixedSize(300,300);
    setLayout(layout);
    show();
}

void Control::dropControl()
{
    dropButton->setEnabled(false);

}

void Control::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
        cout<<"test"<<endl;
        break;
    default:
        cout<<"test"<<endl;
    }
}

void Control::leftControl()
{

}

void Control::rightControl()
{

}

void Control::rotateControl()
{

}

