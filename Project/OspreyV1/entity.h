#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QRect>
#include "sprite.h"


typedef qint64 ms;
enum polarType{WHITE, BLACK};

class Entity
{
public:
    Entity(int x, int y, QString ref);
    virtual ~Entity();

    virtual void move(ms delta);
    void setHorizontalMovement(float dx);
    void setVerticalMovement(float dy);
    float getHorizontalMovement();
    float getVerticalMovement();

    virtual void draw(QPainter * painter);

    virtual void doLogic() = 0;

    int getX(){return static_cast<int>(x);}
    int getY(){return static_cast<int>(y);}

    bool collidesWith(Entity * other);
    virtual void collidedWith(Entity * other);


    QRect getHitBox() const;

    polarType getPolarity() const;

private:

protected:
    float x;
    float y;

    Sprite sprite;
    float dx;
    float dy;

    QRect hitBox;
    polarType polarity;
};




#endif // ENTITY_H
