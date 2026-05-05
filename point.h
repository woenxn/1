#pragma once
#include <iostream>

/**
 * @brief Класс точки на плоскости с целыми неотрицательными координатами
 */
class Point
{
private:
    unsigned int x;
    unsigned int y;

public:
    /**
     * @brief Конструктор по умолчанию. Создаёт точку (0,0)
     */
    Point();

    /**
     * @brief Конструктор с координатами и ограничением по разрешению экрана
     * @param x абсцисса
     * @param y ордината
     * @param maxResolution максимально допустимое значение координаты
     * @warning Если координаты превышают maxResolution, программа завершается с ошибкой
     */
    Point(const unsigned int x,const unsigned int y,const unsigned int maxResolution);

    /**
     * @brief Возвращает абсциссу
     * @return значение x
     */
    unsigned int getX() const;

    /**
     * @brief Возвращает ординату
     * @return значение y
     */
    unsigned int getY() const;

    /**
     * @brief Оператор сравнения на равенство
     * @param other другая точка
     * @return true, если координаты совпадают, иначе false
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор сравнения на неравенство
     * @param other другая точка
     * @return true, если координаты не совпадают, иначе false
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор вывода точки в поток
     * @param os выходной поток
     * @param p точка
     * @return поток os
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Оператор ввода точки из потока
     * @param is входной поток
     * @param p точка
     * @return поток is
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};
