#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H
#include "entity.h"
#include "playerentity.h"

#include <QMainWindow>
#include <QWidget>
#include <QElapsedTimer>
#include <QTimer>

class PlayerEntity;
typedef qint64 ms;

class GameWidget: public QWidget
{
    Q_OBJECT

private:

    enum {WIDTH = 800, HEIGHT = 600};



    bool gameRunning;
    const int FPS;
    const long TARGETTIME;
    float averageFPS;

    QMainWindow * container;
    QWidget * panel;

    PlayerEntity * ship;



    QList<Entity*> entities;
    QList<Entity*> removeList;

    int pressCount;


    bool enemyTrigger;

    bool waitingForKeyPressed;

    QString message;


    void initEntities();
public:
    GameWidget(QWidget *parent = 0);

    QElapsedTimer eTimer;
    QTimer timer;
    ms getTime(){return eTimer.elapsed();}
    void endGame(){gameRunning = false;}

    void gameLoop();

    void removeEntity(Entity * entity);
    void notifyDeath();
    void startGame();
    void trigger();
    QList<Entity *> &getEntities();

protected:
    void paintEvent(QPaintEvent * e);


    void keyPressEvent(QKeyEvent *k);
    void keyReleaseEvent(QKeyEvent *k);
};

#endif // GAMEWIDGET_H
