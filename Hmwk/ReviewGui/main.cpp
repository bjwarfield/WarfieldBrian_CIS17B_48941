
#include "arrayclass.h"

#include <QApplication>
#include <QLabel>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ArrayClass *array = new ArrayClass(16,16);
    QTextBrowser *browser = new QTextBrowser();
    browser->setText(array->toString());

    browser->show();
    return a.exec();
}
