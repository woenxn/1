#include <iostream>
#include <string>
#include "tringle.h"

/**
 * @brief Объявление функции считывания значения
 */
double getValue(const std::string& prompt);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main() {
    double x1 = getValue("Введите x1: ");
    double y1 = getValue("Введите y1: ");
    double x2 = getValue("Введите x2: ");
    double y2 = getValue("Введите y2: ");
    double x3 = getValue("Введите x3: ");
    double y3 = getValue("Введите y3: ");

    Point A(x1, y1), B(x2, y2), C(x3, y3);
    Triangle tri(A, B, C);

    std::cout << "Радиус вписанной окружности: r = " << tri.getInscribedRadius() << std::endl;
    std::cout << "Радиус описанной окружности: R = " << tri.getCircumscribedRadius() << std::endl;

    return 0;
}

/**
 * @brief Считывает значение, введенное с клавиатуры
 * @param prompt - строка информации
 * @return считанное значение
 */
double getValue(const std::string& prompt) {
    double val = 0;
    std::cout << prompt;
    std::cin >> val;
    if (std::cin.fail()) {
        std::cout << "Ошибка ввода!\n";
        exit(1);
    }
    return val;
}
