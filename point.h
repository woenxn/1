#pragma once
#include <iostream>

/**
 * @brief Класс точки на плоскости с целыми неотрицательными координатами
 */
class Point
{
private:
    int x;
    int y;

    static unsigned int maxResolution;

public:
    /**
     * @brief Конструктор по умолчанию, создаёт точку (0,0)
     */
    Point();

    /**
     * @brief Конструктор с координатами
     * @param x абсцисса
     * @param y ордината
     * @warning Если координаты выходят за пределы, программа завершается с ошибкой
     */
    Point(int x, int y);

    /**
     * @brief Устанавливает разрешение экрана
     * @param resolution максимальное допустимое значение
     * @warning Должен быть вызван до создания любых точек
     */
    static void setMaxResolution(unsigned int resolution);

    /**
     * @brief Возвращает абсциссу
     * @return значение x
     */
    int getX() const;

    /**
     * @brief Возвращает ординату
     * @return значение y
     */
    int getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    Point operator+(int delta) const;
    Point operator-(int delta) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};
