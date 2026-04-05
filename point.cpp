#include "point.h"
#include <cmath>

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

bool Point::operator==(const Point& p) const {
    const double eps = 1e-9;
    return std::fabs(x - p.x) < eps && std::fabs(y - p.y) < eps;
}

bool Point::operator!=(const Point& p) const {
    return !(*this == p);
}
