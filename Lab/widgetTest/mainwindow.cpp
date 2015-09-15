#include "arrayclass.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}

void MainWindow::on_generateButton_clicked()
{
    int x = ui->xSpinBox->value();
    int y = ui->ySpinBox->value();

    ArrayClass* array = new ArrayClass(x,y);

    QString  string( array->toString());

    ui->textBrowser->setText(string);

}
