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
    static void setMaxResolution(const int res);

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

    /**
     * @brief оператор сравнения на равенство
     * @param other другая точкао
     * @return true, если координаты обеих точек совпадают
     */

    bool operator==(const Point& other) const;

    /**
    * @brief оператор сравнения на неравенство
    * @param other другая точка
    * @return true, если координаты точек не совпадают
    */

    bool operator!=(const Point& other) const;

    /**
    * @brief прибавляет целое число к обеим координатам
    * @param delta величина сложения
    * @return новая точка с координатами (x + delta, y + delta)
    * @warning если результат выходит за пределы разрешения, программа завершается с ошибкой
    */

    Point operator+(const int delta) const;

    /**
    * @brief вычитает целое число из обеих координат
    * @param delta Величина вычитания
    * @return новая точка с координатами (x - delta, y - delta)
    * @warning если результат выходит за пределы разрешения, программа завершается с ошибкой
    */

    Point operator-(const int delta) const;

    /**
     * @brief дружественная функция для симметричного сложения int + Point
     * @param delta целое число
     * @param p точка
     * @return новая точка с координатами
     */

    friend Point operator+(const int delta, const Point& p);

    /**
     * @brief дружественный оператор вывода точки в поток
     * @param os выходной поток
     * @param p точка для вывода
     * @return ссылка на поток os
     */

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief дружественный оператор ввода точки из потока
     * @param is входной поток
     * @param p точка для заполненияя
     * @return ссылка на поток is
     */

    friend std::istream& operator>>(std::istream& is, Point& p);
};
