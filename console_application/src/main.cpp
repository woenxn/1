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

int main() {
    std::size_t n = 0;
    std::size_t m = 0;

    std::cout << "Enter n and m: ";
    std::cin >> n >> m;

    const std::size_t rows = n;
    const std::size_t cols = m;

    Matrix<int> matrix(rows, cols);

    std::cout << "Pick type of filling:\n"
        << "1 - random numbers\n"
        << "2 - from keyboard\n"
        << "3 - by zero\n"
        << "4 - by const\n"
        << "> ";

    int choice = 0;
    std::cin >> choice;
    const int menuChoice = choice;

    std::unique_ptr<Generator> generator;

    switch (menuChoice) {
    case 1: {
        int min = 0;
        int max = 0;
        std::cout << "Enter min and max: ";
        std::cin >> min >> max;

        const int minValue = min;
        const int maxValue = max;

        generator = std::make_unique<RandomGenerator>(minValue, maxValue);
        break;
    }
    case 2:
        generator = std::make_unique<IStreamGenerator>(std::cin);
        break;
    case 3:
        generator = std::make_unique<ZeroGenerator>();
        break;
    case 4: {
        int value = 0;
        std::cout << "Enter numbers: ";
        std::cin >> value;

        const int constValue = value;

        generator = std::make_unique<ConstantGenerator>(constValue);
        break;
    }
    default:
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
