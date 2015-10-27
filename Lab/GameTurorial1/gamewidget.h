#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include <QMainWindow>
#include <QWidget>
#include <QElapsedTimer>
#include <QTimer>


class GameWidget: public QWidget
{
    Q_OBJECT

private:
    typedef qint64 ms;

    enum {WIDTH = 800, HEIGHT = 600};


    bool gameRunning;
    const int FPS;
    const long TARGETTIME;

    QMainWindow * container;
    QWidget * panel;


public:
    GameWidget(QWidget *parent = 0);

    QElapsedTimer eTimer;
    QTimer timer;
    ms getTime(){return eTimer.elapsed();}


    void gameLoop();

protected:
    void paintEvent(QPaintEvent * e);


};

#endif // GAMEWIDGET_H
