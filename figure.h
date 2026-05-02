#pragma once
#include <string>
#include <iostream>

/**
 * @brief абстрактный базовый класс "фигура на плоскости"
 */
class Figure
{
public:
    virtual ~Figure() = default;

    virtual void draw(std::ostream& os = std::cout) const = 0;
    virtual void readFromStream(std::istream& is = std::cin) = 0;
    virtual std::string ToString() const = 0;
};
