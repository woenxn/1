#pragma once
#include "figure.h"
#include "point.h"
#include <vector>

/**
 * @brief Класс "Многоугольник" – конкретная фигура на плоскости
 */
class Polygon : public Figure
{
private:
    std::vector<Point> vertices;
    unsigned int maxResolution;

    /**
     * @brief Проверяет корректность многоугольника (не менее 3 вершин, ненулевые стороны)
     * @warning При нарушении програма завершается с ошибкой
     */
    void validate() const;

public:
    /**
     * @brief Конструктор через вектор точек
     * @param vertices вершины многоугольника
     * @param maxResolution максимальная координата
     */
    Polygon(const std::vector<Point>& vertices,const unsigned int maxResolution);

    /**
     * @brief Конструктор через массив пар координат
     * @param coords массив чисел (x1,y1,x2,y2,...)
     * @param count количество элементов в массиве (должно быть чётным >=6)
     * @param maxResolution максимальная координата
     */
    Polygon(const unsigned int coords[],const size_t count,const unsigned int maxResolution);

    /**
     * @brief Статическая сериализация набора вершин в строку
     * @param vertices вершины
     * @return строка вида "Многоугольник: (x1,y1) (x2,y2) ..."
     */
    static std::string ToString(const std::vector<Point>& vertices);

    /**
     * @brief Виртуальный метод сериализации объекта
     * @return строковое представление многоугольника
     */
    std::string ToString() const override;

    /**
     * @brief Вывод многоугольника в поток (рисование)
     * @param os выходной поток
     */
    void draw(std::ostream& os = std::cout) const override;

    /**
     * @brief Чтение многоугольника из потока (заменяет текущий объект)
     * @param is входной поток
     */
    void readFromStream(std::istream& is = std::cin) override;

    /**
     * @brief Статический метод чтения многоугольника из потока
     * @param is входной поток
     * @param maxResolution максимальная координата
     * @return новый объект Polygon
     */
    static Polygon readFromStream(std::istream& is,const unsigned int maxResolution);

    /**
     * @brief Оператор вывода многоугольника в поток
     * @param os выходной поток
     * @param poly многоугольник
     * @return поток os
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& poly);
};
