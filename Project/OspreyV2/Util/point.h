#ifndef POINT_H
#define POINT_H

#include <QPoint>
#include <QtMath>



class Point
{
private:
    float px;
    float py;

public:
    Point(float x=0,float y=0){px = x;py = y;}
    Point(QPoint point){px = point.x();  py = point.y();}
    Point(const Point &point){px = point.x();  py = point.y();}

    void setPotion(float px, float py);

    void setX(float x){px = x;}

    void setY(float y){py = y;}

    float x() const{return px;}

    float y() const{return py;}

    float &rx(){return px;}

    float &ry(){return py;}

    void operator=(const Point &point){px = point.x(); py = point.y();}

    void operator =(const QPoint &point){px = point.x(); py = point.y();}

    Point operator-(const Point &point)const{
        return Point(px - point.x(), py - point.y());
    }

    Point operator+(const Point &point)const{
        return Point(px + point.x(), py + point.y());
    }

    Point operator*(const Point &point)const{
        return Point(px * point.x(), py * point.y());
    }

    Point normalize()const{

        float nx = px / qSqrt(px*px + py*py);
        float ny = py / qSqrt(px*px + py*py);
//        return Point(px < 0 ? -nx : nx, py < 0 ? -ny : ny);
        return Point( nx, ny);
    }

//    Point truncate(float max)const{
//        float i = max / this->distanceTo(Point(0,0));
//        i = i < 1.0f ? 1.0f : i;

//        return Point(i * px,i * py);

//    }

    //return distance to point
    float distanceTo(const Point &point)const{
        return qSqrt((px - point.x())*(px - point.x()) + (py - point.y())*(py - point.y()));
    }
    float distanceTo(float x, float y)const{
        return distanceTo(Point(x,y));
    }

    //return angle to point in degrees (-180 < value < 180)
    float angleTo(const Point &point){
        float angle = qRadiansToDegrees(qAtan2(point.x()-px,point.y()-py));

        if (angle > 180) {
            angle -= 360;
        } else if (angle < -180) {
            angle += 360;
        }
        return angle;
    }


};

#endif // POINT_H
