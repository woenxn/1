#include <iostream>

#include "Matrix.h"
#include "Task1.h"
#include "Task2.h"
#include "RandomGenerator.h"
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"
#include "IStreamGenerator.h"

using namespace miit::algebra;

namespace {

    /**
     * @brief Способы заполнения матрицы.
     */
    enum class FillType {
        Random = 1,
        Keyboard,
        Zero,
        Constant
    };

}

/**
 * @brief Демонстрация работы задач и сдвигов.
 * Матрица заполняется в конструкторе Task1 с помощью переданного генератора.
 * @param n Количество строк.
 * @param m Количество столбцов.
 * @param generator Ссылка на конкретный генератор.
 */
void runDemo(const std::size_t n, const std::size_t m,const Generator& generator);

/**
 * @brief Точка входа в демонстрационную программу.
 * @return Код возврата (0 при успехе).
 */
int main() {
    std::size_t n = 0;
    std::size_t m = 0;

    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    std::cout << "Pick type of filling:\n"
        << static_cast<int>(FillType::Random) << " - random numbers\n"
        << static_cast<int>(FillType::Keyboard) << " - from keyboard\n"
        << static_cast<int>(FillType::Zero) << " - by zero\n"
        << static_cast<int>(FillType::Constant) << " - by const\n"
        << "> ";

    int choice = 0;
    std::cin >> choice;

    switch (static_cast<FillType>(choice)) {
    case FillType::Random: {
        int min = 0;
        int max = 0;
        std::cout << "Enter min and max: ";
        std::cin >> min >> max;

        RandomGenerator generator(min, max);
        runDemo(n, m, generator);
        break;
    }
    case FillType::Keyboard: {
        IStreamGenerator generator(std::cin);
        runDemo(n, m, generator);
        break;
    }
    case FillType::Zero: {
        ZeroGenerator generator;
        runDemo(n, m, generator);
        break;
    }
    case FillType::Constant: {
        int value = 0;
        std::cout << "Enter number: ";
        std::cin >> value;

        ConstantGenerator generator(value);
        runDemo(n, m, generator);
        break;
    }
    default:
        std::cout << "Wrong choice.\n";
        return 1;
    }

    return 0;
}

void runDemo(const std::size_t n, const std::size_t m, Generator& generator) {
    Matrix<int> matrix(n, m);
    Task1 task1(matrix, generator);

    std::cout << "\nInitial matrix:\n";
    std::cout << matrix.toString();

    // Копии исходной матрицы для Task2 и сдвигов.
    Matrix<int> shifted = matrix;

    // Пустая матрица: конструктор Task2 ничего не запрашивает у генератора.
    Matrix<int> matrix2;
    Task2 task2(matrix2, generator);
    matrix2 = matrix;

    task1.solve();

    std::cout << "\nTask1: min element of each column is replaced by zero:\n";
    std::cout << matrix.toString();

    task2.solve();

    std::cout << "\nTask2: last row has been inserted after the rows containing the element with the max absolute value:\n";
    std::cout << matrix2.toString();

    shifted << 1;

    std::cout << "\nshift left by 1:\n";
    std::cout << shifted.toString();

    shifted >> 2;

    std::cout << "\nshift right by 2:\n";
    std::cout << shifted.toString();
}
