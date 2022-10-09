#ifndef POINT_H
#define POINT_H
#include <math.h>

class Point
{
public:
    Point(float x, float y, float z):x(x), y(y), z(z) {

    };

    Point() = default;

    Point(const Point&) = default;

    Point sub(Point p) {
        Point _p;
        _p.x = x-p.x;
        _p.y = y-p.y;
        _p.z = z - p.z;
        return _p;
    }

    float l2() {
        return x*x+y*y+z*z;
    }

    Point norm() {
        float l = sqrt(l2());
        Point y(*this);
        y.setMult(1/l);
        return y;
    }

    Point add(Point p) {
        Point _p;
        _p.x = x+p.x;
        _p.y = y+p.y;
        _p.z = z + p.z;
        return _p;
    }

    Point setAdd(Point p) {
        x+=p.x;
        y+=p.y;
        z+=p.z;
        return *this;
    }

    Point setSub(Point p) {
        x-=p.x;
        y-=p.y;
        z-=p.z;
        return *this;
    }

    Point setMult(float _x) {
        x*=_x;
        y*=_x;
        z*=_x;
        return *this;
    }

    float multScal(Point p) {
        return x*p.x+y*p.y+z*p.z;
    }

    Point mult(Point p) {
        Point p1(*this);
        p1.x = y*p.z - z*p.y;
        p1.y = z*p.x - x*p.z;
        p1.z = x*p.y - y*p.x;
        return p1;
    }

    Point mult(float _x) {
        Point _p(*this);
        _p.x*=_x;
        _p.y*=_x;
        _p.z*=_x;
        return _p;
    }

    float x;
    float y;
    float z;

};

#endif // POINT_H
