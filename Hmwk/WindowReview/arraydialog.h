#ifndef ARRAYDIALOG_H
#define ARRAYDIALOG_H

#include <QDialog>

namespace Ui {
class QDialog;
}
class arraydialog : public QDialog
{
    Q_OBJECT

public:
    explicit arraydialog(QWidget *parent = 0);
    ~arraydialog();

private:
    Ui::QDialog *ui;
};

#endif // ARRAYDIALOG_H
