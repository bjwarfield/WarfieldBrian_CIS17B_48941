#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "derived.h"

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
 ;
    Derived d( ui->xBox->value(), ui->yBox->value());
    ui->textBrowser->setText(d.toString());
}
