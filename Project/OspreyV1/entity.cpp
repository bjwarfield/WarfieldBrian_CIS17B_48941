#include <entity.h>


Entity::Entity(int x, int y, QString ref):
    x(x),y(y),sprite(ref),
    hitBox(x,y,sprite.getWidth(),sprite.getHeight())
{

}

Entity::~Entity()
{

}

void Entity::move(ms delta)
{
    x += (delta * dx) / 1000;
    y += (delta * dy) / 1000;
    hitBox.setRect(getX()-sprite.getWidth()/2,getY()-sprite.getHeight()/2,
                   sprite.getWidth(),sprite.getHeight());

}

void Entity::setHorizontalMovement(float dx)
{
    this->dx = dx;
}

void Entity::setVerticalMovement(float dy)
{
    this->dy = dy;
}

float Entity::getHorizontalMovement()
{
    return dx;
}

float Entity::getVerticalMovement()
{
    return dy;
}


void Entity::draw(QPainter *painter)
{
    sprite.draw(painter, getX(), getY());
}

bool Entity::collidesWith(Entity * other)
{
    return hitBox.intersects(other->getHitBox());
}

void Entity::collidedWith(Entity *other)
{
    return;
}
QRect Entity::getHitBox() const
{
    return hitBox;
}
polarType Entity::getPolarity() const
{
    return polarity;
}




