#include <iostream>
#include <vector>
#include <memory>
#include "polygon.h"

/**
 * @brief Точка входа в программу.
 * @return 0 при успешном выполнении
 */

int main()
{
    const unsigned int SCREEN_RES = 1024;

    std::vector<Point> points = {
        Point(100, 100, SCREEN_RES),
        Point(200, 100, SCREEN_RES),
        Point(200, 200, SCREEN_RES),
        Point(100, 200, SCREEN_RES)
    };
    Polygon square(points, SCREEN_RES);

    unsigned int coords[] = { 300, 300, 400, 300, 350, 400 };
    Polygon triangle(coords, 6, SCREEN_RES);

    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Polygon>(square));
    figures.push_back(std::make_unique<Polygon>(triangle));

    for (const auto& fig : figures)
        fig->draw();

    std::cout << "\nВведите многоугольник (количество вершин, затем координаты):\n";
    Polygon p = Polygon::readFromStream(std::cin, SCREEN_RES);
    std::cout << "Прочитан: " << p << std::endl;

    return 0;
}
