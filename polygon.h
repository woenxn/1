#pragma once
#include "figure.h"
#include "point.h"
#include <vector>

/**
 * @brief класс "Многоугольник" – конкретная фигура на плоскости
 */
class Polygon : public Figure
{
private:
    std::vector<Point> vertices;

    static unsigned int maxResolution;

    /**
     * @brief проверяет корректность многоугольника (не менее 3 вершин, ненулевые стороны)
     * @warning при нарушении программа завершается с ошибкой
     */
    void validate() const;

public:
    /**
     * @brief конструктор через вектор точек
     * @param vertices вершины многоугольника
     */
    Polygon(const std::vector<Point>& vertices);

    /**
     * @brief конструктор через массив пар координат
     * @param coords массив чисел (x1,y1,x2,y2,...)
     * @param count количество элементов в массиве (должно быть чётным >=6)
     */
    Polygon(const int coords[], size_t count);

    /**
     * @brief статическая сериализация набора вершин в строку
     * @param vertices вершины
     * @return строка вида "Многоугольник: (x1,y1) (x2,y2) ..."
     */
    static std::string ToString(const std::vector<Point>& vertices);

    /**
     * @brief виртуальный метод сериализации объекта
     * @return строковое представление многоугольника
     */
    std::string ToString() const override;

    /**
     * @brief вывод многоугольника в поток
     * @param os выходной поток
     */
    void draw(std::ostream& os = std::cout) const override;

    /**
     * @brief чтение многоугольника из потока (заменяет текущий объект)
     * @param is входной поток
     */
    void readFromStream(std::istream& is = std::cin) override;

    /**
     * @brief статический метод чтения многоугольника из потока
     * @param is входной поток
     * @return новый объект polygon
     */
    static Polygon readFromStream(std::istream& is);

    /**
     * @brief оператор вывода многоугольника в поток
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& poly);
};
