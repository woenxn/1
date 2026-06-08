#include <iostream>
#include <vector>
#include <memory>
#include "polygon.h"

int main()
{
    Point::setMaxResolution(1920);

    std::vector<Point> points = {
        Point(100, 100),
        Point(200, 100),
        Point(200, 200),
        Point(100, 200)
    };
    Polygon square(points);

    int coords[] = { 300, 300, 400, 300, 350, 400 };
    Polygon triangle(coords, 6);

    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Polygon>(square));
    figures.push_back(std::make_unique<Polygon>(triangle));

    for (const auto& fig : figures)
        fig->draw();

    std::cout << "\nВведите многоугольник (количество вершин, затем координаты):\n";
    Polygon p = Polygon::readFromStream(std::cin);
    std::cout << "Прочитан: " << p << std::endl;

    return 0;
}
