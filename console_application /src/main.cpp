#include <iostream>
#include <memory>

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

    /**
     * @brief Создает генератор по выбранному способу заполнения.
     * @param type Выбранный способ заполнения.
     * @return Умный указатель на созданный генератор или nullptr, если способ неизвестен.
     */
    std::unique_ptr<Generator> createGenerator(const FillType type) {
        switch (type) {
        case FillType::Random: {
            int min = 0;
            int max = 0;
            std::cout << "Enter min and max: ";
            std::cin >> min >> max;
            return std::make_unique<RandomGenerator>(min, max);
        }
        case FillType::Keyboard:
            return std::make_unique<IStreamGenerator>(std::cin);
        case FillType::Zero:
            return std::make_unique<ZeroGenerator>();
        case FillType::Constant: {
            int value = 0;
            std::cout << "Enter number: ";
            std::cin >> value;
            return std::make_unique<ConstantGenerator>(value);
        }
        }

        return nullptr;
    }

}

/**
 * @brief Точка входа в демонстрационную программу.
 * Демонстрирует заполнение матрицы, работу задач Task1 и Task2, а также сдвиги.
 * @return Код возврата (0 при успехе).
 */
int main() {
    std::size_t n = 0;
    std::size_t m = 0;

    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    Matrix<int> matrix(n, m);

    std::cout << "Pick type of filling:\n"
        << static_cast<int>(FillType::Random) << " - random numbers\n"
        << static_cast<int>(FillType::Keyboard) << " - from keyboard\n"
        << static_cast<int>(FillType::Zero) << " - by zero\n"
        << static_cast<int>(FillType::Constant) << " - by const\n"
        << "> ";

    int choice = 0;
    std::cin >> choice;

    const std::unique_ptr<Generator> generator = createGenerator(static_cast<FillType>(choice));

    if (!generator) {
        std::cout << "Wrong choice.\n";
        return 1;
    }

    Task1 filler(matrix, *generator);
    filler.fill();

    std::cout << "\nInitial matrix:\n";
    std::cout << matrix.toString();

    Matrix<int> matrix1 = matrix;
    Task1 task1(matrix1, *generator);
    task1.solve();

    std::cout << "\nTask1: min element of each column is replaced by zero:\n";
    std::cout << matrix1.toString();

    Matrix<int> matrix2 = matrix;
    Task2 task2(matrix2, *generator);
    task2.solve();

    std::cout << "\nTask2: last row has been inserted after the rows containing the element with the max absolute value:\n";
    std::cout << matrix2.toString();

    Matrix<int> shifted = matrix;
    shifted << 1;

    std::cout << "\nshift left by 1:\n";
    std::cout << shifted.toString();

    shifted >> 2;

    std::cout << "\nshift right by 2:\n";
    std::cout << shifted.toString();

    return 0;
}
