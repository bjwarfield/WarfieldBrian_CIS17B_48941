#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QString>
#include <iostream>
#include <QFrame>
#include <QKeyEvent>

using namespace std;

class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(QWidget *parent = 0);
    QGridLayout *layout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *dropButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *swapButton;
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:
    void dropControl();
    void leftControl();
    void rightControl();
    void rotateControl();
};

#endif // CONTROL_H
