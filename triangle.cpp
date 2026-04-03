#include "triangle.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {
    if (p1 == p2 || p2 == p3 || p1 == p3) {
        std::cout << "Ошибка: Точки совпадают!\n";
        exit(1);
    }
    calculate();
    if (area == 0.0) {
        std::cout << "Ошибка: Треугольник вырожден (точки на одной прямой)!\n";
        exit(1);
    }
}

void Triangle::calculate() {
    double dx12 = p2.getX() - p1.getX();
    double dy12 = p2.getY() - p1.getY();
    double dx23 = p3.getX() - p2.getX();
    double dy23 = p3.getY() - p2.getY();
    double dx31 = p1.getX() - p3.getX();
    double dy31 = p1.getY() - p3.getY();

    sideA = std::hypot(dx23, dy23);
    sideB = std::hypot(dx31, dy31); 
    sideC = std::hypot(dx12, dy12); 

    area = std::fabs((p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
                     (p3.getX() - p1.getX()) * (p2.getY() - p1.getY())) / 2.0;
}

double Triangle::getSideA() const { return sideA; }
double Triangle::getSideB() const { return sideB; }
double Triangle::getSideC() const { return sideC; }

double Triangle::getPerimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::getArea() const {
    return area;
}

double Triangle::getInscribedRadius() const {
    return 2.0 * area / getPerimeter();
}

double Triangle::getCircumscribedRadius() const {
    return (sideA * sideB * sideC) / (4.0 * area);
}
