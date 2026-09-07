#include "polygon.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>

void Polygon::validate() const
{
    if (vertices.size() < 3)
    {
        std::cout << "Error. A polygon must have at least 3 vertices.\n";
        exit(1);
    }
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        if (p1 == p2)
        {
            std::cout << "Error. The side of the polygon has a length of zero.\n";
            exit(1);
        }
    }
}

Polygon::Polygon(const std::vector<Point>& vertices)
    : vertices(vertices)
{
    unsigned int maxRes = Point::getMaxResolution();
    for (const auto& p : vertices)
    {
        if (p.getX() < 0 || p.getY() < 0 ||
            static_cast<unsigned int>(p.getX()) > maxRes ||
            static_cast<unsigned int>(p.getY()) > maxRes)
        {
            std::cout << "Error. The vertex is outside the screen resolution.\n";
            exit(1);
        }
    }
    validate();
}

Polygon::Polygon(const int coords[],const size_t count)
{
    if (count < 6 || count % 2 != 0)
    {
        std::cout << "Error. The number of coordinates must be even and at least 6.\n";
        exit(1);
    }
    std::vector<Point> temp;
    unsigned int maxRes = Point::getMaxResolution();
    for (size_t i = 0; i < count; i += 2)
    {
        if (coords[i] < 0 || coords[i+1] < 0 ||
            static_cast<unsigned int>(coords[i]) > maxRes ||
            static_cast<unsigned int>(coords[i+1]) > maxRes)
        {
            std::cout << "Error. The coordinate is outside the screen resolution.\n";
            exit(1);
        }
        temp.push_back(Point(coords[i], coords[i+1]));
    }
    vertices = temp;
    validate();
}

std::string Polygon::ToString(const std::vector<Point>& vertices)
{
    std::ostringstream oss;
    oss << "Polygon: ";
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

Polygon Polygon::readFrom(std::istream& is)
{
    size_t vertexCount;
    is >> vertexCount;
    if (vertexCount < 3)
    {
        std::cout << "Error. The number of vertices must be at least 3.\n";
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
    *this = readFrom(is);
}
