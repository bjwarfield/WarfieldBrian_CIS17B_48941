#ifndef SPRITE_H
#define SPRITE_H

#include <QPainter>
#include <QPixMap>



class Sprite
{
public:
    Sprite(QString ref);
    Sprite(QString ref, QPixmap img);

    int getWidth();
    int getHeight();
    virtual void draw(QPainter * painter, int x, int y);

    QString getRef() const;

    QPixmap getImage() const;

private:
    QString ref;
    QPixmap image;

};

#endif // SPRITE_H
