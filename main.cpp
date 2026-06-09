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

    std::cout << "\nEnter a polygon (number of vertices, then coordinates):\n";
    Polygon p = Polygon::readFrom(std::cin);
    std::cout << "Read it: " << p << std::endl;

    return 0;
}
