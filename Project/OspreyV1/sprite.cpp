#include "sprite.h"


Sprite::Sprite(QString ref):
    ref(ref), image(ref)
{

}

Sprite::Sprite(QString ref, QPixmap img):
    ref(ref), image(img)
{

}

int Sprite::getWidth()
{
    return image.width();
}

int Sprite::getHeight()
{
    return image.height();
}

void Sprite::draw(QPainter *painter, int x, int y)
{
  painter->drawPixmap(x-image.width()/2, y-image.height()/2, image);
}
QString Sprite::getRef() const
{
    return ref;
}
QPixmap Sprite::getImage() const
{
    return image;
}




