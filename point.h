#pragma once
/**
 * @brief Класс Точка
 */
class Point
{
private:
    /**
     * @brief Координата X
     */
    double x;
    /**
     * @brief Координата Y
     */
    double y;

public:
    /**
     * @brief Конструктор точки
     */
    Point(const double x = 0, const double y = 0);

    /**
     * @brief Получение координаты X
     */
    double getX() const;

    /**
     * @brief Получение координаты Y
     */
    double getY() const;

    /**
     * @brief Проверка на равенство оператора
     */
    bool operator==(const Point p) const;

    /**
     * @brief Проверка на неравенство оператора
     */
    bool operator!=(const Point p) const;
};
