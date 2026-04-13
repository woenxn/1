#include "point.h"
#include <cmath>
#include <cfloat>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& p) const {
    return std::fabs(x - p.x) < DBL_EPSILON && std::fabs(y - p.y) < DBL_EPSILON;
}

bool Point::operator!=(const Point& p) const {
    return !(*this == p);
}
