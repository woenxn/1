#pragma once
#include "point.h"

/**
 * @brief Класс треугольник
 */
class Triangle
{
private:
    /**
     * @brief Первая вершина
     */
    Point p1;
    /**
     * @brief Вторая вершина
     */
    Point p2;
    /**
     * @brief Третья вершина
     */
    Point p3;

    /**
     * @brief Длина стороны BC
     */
    double sideA;
    /**
     * @brief Длина стороны CA
     */
    double sideB;
    /**
     * @brief Длина стороны AB
     */
    double sideC;
    /**
     * @brief Площадь треугольника
     */
    double area;

    /**
     * @brief Вычисление сторон и площади
     */
    void calculate();

public:
    /**
     * @brief Конструктор
     * @param p1 - первая точка
     * @param p2 - вторая точка
     * @param p3 - третья точка
     */
    Triangle(const Point p1, const Point p2, const Point p3);

    /**
     * @brief Получение длины стороны a(BC)
     */
    double getSideA() const;
    /**
     * @brief Получение длины стороны b(CA)
     */
    double getSideB() const;
    /**
     * @brief Получение длины стороны c(AB)
     */
    double getSideC() const;

    /**
     * @brief Нахождение периметра
     */
    double getPerimeter() const;

    /**
     * @brief Нахождение площади
     */
    double getArea() const;

    /**
     * @brief Расчет радиуса вписанной окружности
     */
    double getInscribedRadius() const;

    /**
     * @brief Расчет радиуса описанной окружности
     */
    double getCircumscribedRadius() const;
};
