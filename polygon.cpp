#include "polygon.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>

unsigned int Polygon::maxResolution = 1024;

void Polygon::validate() const
{
    if (vertices.size() < 3)
    {
        std::cout << "Ошибка. Многоугольник должен иметь не менее 3 вершин.\n";
        exit(1);
    }
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        if (p1 == p2)
        {
            std::cout << "Ошибка. Сторона многоугольника имеет нулевую длину.\n";
            exit(1);
        }
    }
}

Polygon::Polygon(const std::vector<Point>& vertices)
    : vertices(vertices)
{
    for (const auto& p : vertices)
    {
        if (p.getX() < 0 || p.getY() < 0 || 
            static_cast<unsigned int>(p.getX()) > maxResolution ||
            static_cast<unsigned int>(p.getY()) > maxResolution)
        {
            std::cout << "Ошибка. Вершина выходит за пределы разрешения экрана.\n";
            exit(1);
        }
    }
    validate();
}

Polygon::Polygon(const int coords[], size_t count)
{
    if (count < 6 || count % 2 != 0)
    {
        std::cout << "Ошибка. Количество координат должно быть чётным и не менее 6.\n";
        exit(1);
    }
    std::vector<Point> temp;
    for (size_t i = 0; i < count; i += 2)
    {
        temp.push_back(Point(coords[i], coords[i+1]));
    }
    vertices = temp;
    validate();
}

std::string Polygon::ToString(const std::vector<Point>& vertices)
{
    std::ostringstream oss;
    oss << "Многоугольник: ";
    for (const auto& p : vertices)
        oss << p << " ";
    return oss.str();
}

std::string Polygon::ToString() const
{
    return ToString(vertices);
}

void Polygon::draw(std::ostream& os) const
{
    os << ToString() << std::endl;
}

Polygon Polygon::readFromStream(std::istream& is)
{
    size_t vertexCount;
    is >> vertexCount;
    if (vertexCount < 3)
    {
        std::cout << "Ошибка. Количество вершин должно быть не менее 3.\n";
        exit(1);
    }
    std::vector<Point> verts;
    for (size_t i = 0; i < vertexCount; ++i)
    {
        int x, y;
        is >> x >> y;
        verts.push_back(Point(x, y));
    }
    return Polygon(verts);
}

void Polygon::readFromStream(std::istream& is)
{
    *this = readFromStream(is);
}

std::ostream& operator<<(std::ostream& os, const Polygon& poly)
{
    os << poly.ToString();
    return os;
}
