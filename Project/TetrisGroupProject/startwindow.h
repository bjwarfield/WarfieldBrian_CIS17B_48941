#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include "tetriswindow.h"
#include <QtWidgets>
#include <QDesktopWidget>


class StartWindow : public QWidget
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = 0);

private:
    QDesktopWidget *monitor;
    QPixmap *backGround;
    QLabel *backGroundLabel;
    QPushButton *startButton;
    QVBoxLayout *boxLayout;
signals:

public slots:
    void gameStart();
};

#endif // STARTWINDOW_H
