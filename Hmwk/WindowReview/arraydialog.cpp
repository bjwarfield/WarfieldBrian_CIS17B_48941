#include "arraydialog.h"
#include "ui_arraydialog.h"

arraydialog::arraydialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog())
{
    ui->setupUi(this);
}

arraydialog::~arraydialog(){
    delete ui;
}

