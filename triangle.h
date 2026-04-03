#pragma once
#include "point.h"

class Triangle {
private:
    Point p1, p2, p3;
    double sideA, sideB, sideC;
    double area;
    void calculate();
public:
    Triangle(Point p1, Point p2, Point p3);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getPerimeter() const;
    double getArea() const;
    double getInscribedRadius() const;
    double getCircumscribedRadius() const;
};
