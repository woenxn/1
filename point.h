#pragma once
#include <iostream>

/**
 * @brief класс точки на плоскости с целыми неотрицательными координатами
 */
class Point
{
private:
    unsigned int x;
    unsigned int y;

public:
    Point();
    Point(unsigned int x, unsigned int y, unsigned int maxResolution);

    unsigned int getX() const;
    unsigned int getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};
