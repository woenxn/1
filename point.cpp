#include "point.h"
#include <iostream>
#include <cstdlib>

unsigned int Point::maxResolution = 0;

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y)
{
    if (maxResolution == 0)
    {
        std::cout << "Ошибка. Не установлено разрешение экрана.\n";
        exit(1);
    }
    if (x < 0 || y < 0 || static_cast<unsigned int>(x) > maxResolution || static_cast<unsigned int>(y) > maxResolution)
    {
        std::cout << "Ошибка. Координаты точки выходят за пределы [0, " << maxResolution << "].\n";
        exit(1);
    }
    this->x = x;
    this->y = y;
}

void Point::setMaxResolution(unsigned int resolution)
{
    if (resolution == 0)
    {
        std::cout << "Ошибка. Разрешение экрана должно быть больше 0.\n";
        exit(1);
    }
    maxResolution = resolution;
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }

bool Point::operator==(const Point& other) const
{
    return (x == other.x) && (y == other.y);
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

Point Point::operator+(int delta) const
{
    return Point(x + delta, y + delta);
}

Point Point::operator-(int delta) const
{
    return Point(x - delta, y - delta);
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
