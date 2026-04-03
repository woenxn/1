#pragma once

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    bool operator==(const Point& p) const;
    bool operator!=(const Point& p) const;
};
