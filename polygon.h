#pragma once
#include "figure.h"
#include "point.h"
#include <vector>

class Polygon : public Figure
{
private:
    std::vector<Point> vertices;
    unsigned int maxResolution;

    void validate() const;

public:
    Polygon(const std::vector<Point>& vertices, unsigned int maxResolution);
    Polygon(const unsigned int coords[], size_t count, unsigned int maxResolution);

    static std::string ToString(const std::vector<Point>& vertices);
    std::string ToString() const override;
    void draw(std::ostream& os = std::cout) const override;
    void readFromStream(std::istream& is = std::cin) override;
    static Polygon readFromStream(std::istream& is, unsigned int maxResolution);

    friend std::ostream& operator<<(std::ostream& os, const Polygon& poly);
};
