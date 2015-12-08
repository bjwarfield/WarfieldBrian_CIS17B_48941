#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H
#include <QVector>
#include "Entity/entity.h"
#include "Main/gamewidget.h"

class GameWidget;

//path following behavior
struct Path{
private:
    QVector<Point> nodes;
public:
    void addNode(Point node){nodes.append(node);}
    QVector<Point> getNodes()const{return nodes;}
};

class EnemyEntity: public Entity
{

public:
    EnemyEntity(GameState *game, int x, int y, polarType polarity = WHITE,
                Path *path = NULL, QString ref = ":/sprites/enemy/scout.png");
    void draw(QPainter *painter)Q_DECL_OVERRIDE;
    void doLogic(double delta)Q_DECL_OVERRIDE;
    bool isDead();
    void shoot(int speed, const e_ptr &target, float deg);
    void shoot(int speed, QPoint target, float deg);
    void collidedWith(const e_ptr &other)Q_DECL_OVERRIDE;

    ~EnemyEntity();

protected:
    GameState *game;

    int maxHealth;
    int health;
    int value;
    bool hit;
    bool dead;
    int gunX;
    int gunY;


    double startTime;
    double elapsed;
    double ticker;
    int moveTicks;
    int lastMove;
    int shotTicks;
    int lastShot;

    float angle;
    int speed;

    Point target;
    float targetAngle;

    Path *path;
    int currentNode;

    Point tv;//target bector
    Point sv;//steering vector


    void seek(const Point &trgt, double delta);
    void followPath(double delta);
    void parseFrames(int cols, int rows);




};

#endif // ENEMYENTITY_H
