#include "point.h"
#include <iostream>
#include <cstdlib>

Point::Point() : x(0), y(0) {}

Point::Point(unsigned int x, unsigned int y, unsigned int maxResolution)
{
    if (x > maxResolution || y > maxResolution)
    {
        std::cout << "Ошибка. Координаты точки превышают разрешение экрана\n";
        exit(1);
    }
    this->x = x;
    this->y = y;
}

unsigned int Point::getX() const { return x; }
unsigned int Point::getY() const { return y; }

bool Point::operator==(const Point& other) const
{
    return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}
