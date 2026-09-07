#pragma once
#include <string>
#include <iostream>

/**
 * @brief Абстрактный базовый класс "Фигура на плоскости"
 */
class Figure
{
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Figure() = default;

    /**
     * @brief "Рисует" фигуру, выводя её строковое представление в поток
     * @param os выходной поток (по умолчанию std::cout)
     */
    virtual void draw(std::ostream& os = std::cout) const = 0;

    /**
     * @brief Считывает фигуру из входного потока
     * @param is входной поток (по умолчанию std::cin)
     */
    virtual void readFromStream(std::istream& is = std::cin) = 0;

    /**
     * @brief Сериализует фигуру в строку
     * @return строковое представление фигуры
     */
    virtual std::string ToString() const = 0;

    /**
    * @brief оператор вывода фигуры в поток 
    * @param os выходной поток
    * @param fig фигура
    * @return ссылка на поток
    */

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
};
