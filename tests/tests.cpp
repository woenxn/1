#include <cassert>
#include <vector>

#include "Matrix.h"
#include "Task1.h"
#include "Task2.h"
#include "ConstantGenerator.h"
#include "ZeroGenerator.h"
#include "RandomGenerator.h"

using namespace miit::algebra;

namespace {

    // Наследник Generator, возвращающий 1, 2, 3, ...
    class CounterGenerator : public Generator {
    private:
        int current = 0;

    public:
        int generate() override {
            return ++current;
        }
    };

}

void testTask1() {
    Matrix<int> matrix(3, 3);
    ConstantGenerator generator(0);
    Task1 task(matrix, generator);

    matrix = std::vector<std::vector<int>>{
        { 3, -5, 2 },
        { 1, -5, 4 },
        { 9,  0, 2 }
    };

    task.solve();

    assert(matrix[0][0] == 3);
    assert(matrix[1][0] == 0);
    assert(matrix[2][0] == 9);

    assert(matrix[0][1] == 0);
    assert(matrix[1][1] == 0);
    assert(matrix[2][1] == 0);

    assert(matrix[0][2] == 0);
    assert(matrix[1][2] == 4);
    assert(matrix[2][2] == 0);
}

void testTask2() {
    Matrix<int> matrix(3, 2);
    ConstantGenerator generator(0);
    Task2 task(matrix, generator);

    matrix = std::vector<std::vector<int>>{
        { 1, 2 },
        { 3, 4 },
        { 5, 6 }
    };

    task.solve();

    assert(matrix.getRows() == 4);
    assert(matrix[3][0] == 5);
    assert(matrix[3][1] == 6);
}

void testPolymorphicGenerator() {
    // Конструктор Exercise заполняет матрицу через Generator&,
    // при этом вызывается generate() производного класса.
    Matrix<int> counter(2, 2);
    CounterGenerator counterGenerator;
    Task1 counterTask(counter, counterGenerator);
    assert(counter[0][0] == 1 && counter[0][1] == 2);
    assert(counter[1][0] == 3 && counter[1][1] == 4);

    Matrix<int> zeros(2, 2, 9);
    ZeroGenerator zeroGenerator;
    Task1 zeroTask(zeros, zeroGenerator);
    assert(zeros[0][0] == 0 && zeros[1][1] == 0);

    Matrix<int> constant(2, 2);
    ConstantGenerator constantGenerator(7);
    Task2 constantTask(constant, constantGenerator);
    assert(constant[0][1] == 7 && constant[1][0] == 7);

    Matrix<int> random(2, 2);
    RandomGenerator randomGenerator(5, 5);
    Task1 randomTask(random, randomGenerator);
    assert(random[0][0] == 5 && random[1][1] == 5);
}

int main() {
    testTask1();
    testTask2();
    testPolymorphicGenerator();

    return 0;
}
