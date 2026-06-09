#pragma once
#include <iostream>

/**
 * @brief класс точки на плоскости с целыми неотрицательными координатами
 */
class Point
{
private:
    int x;
    int y;

    static unsigned int maxResolution;  

public:
    /**
     * @brief конструктор по умолчанию, создаёт точку (0,0)
     */
    Point();

    /**
     * @brief конструктор с координатами
     * @param x абсцисса
     * @param y ордината
     * @warning если координаты выходят за пределы, программа завершается с ошибкой
     */
    Point(const int x, const int y);

    /**
     * @brief задаёт максимальное разрешение экрана
     * @param res новое значение разрешения (должно быть > 0)
     */
    static void setMaxResolution(unsigned int res);

    /**
     * @brief возвращает текущее максимальное разрешение
     */
    static unsigned int getMaxResolution();

    /**
     * @brief возвращает абсциссу
     */
    int getX() const;

    /**
     * @brief возвращает ординату
     */
    int getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    Point operator+(const int delta) const;
    Point operator-(const int delta) const;

    friend Point operator+(int delta, const Point& p);

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};
