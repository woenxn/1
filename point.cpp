#include "point.h"

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& p) const {
    return x == p.x && y == p.y;
}

bool Point::operator!=(const Point& p) const {
    return !(*this == p);
}
