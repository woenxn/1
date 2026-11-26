#include <cassert>
#include <cstddef>
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

bool compare(const Matrix<int>& actual, const Matrix<int>& expected);
void testTask1();
void testTask2();
void testPolymorphicGenerator();

int main() {
    testTask1();
    testTask2();
    testPolymorphicGenerator();

    return 0;
}

bool compare(const Matrix<int>& actual, const Matrix<int>& expected) {
    if (actual.getRows() != expected.getRows() || actual.getCols() != expected.getCols()) {
        return false;
    }

    for (std::size_t i = 0; i < actual.getRows(); ++i) {
        for (std::size_t j = 0; j < actual.getCols(); ++j) {
            if (actual[i][j] != expected[i][j]) {
                return false;
            }
        }
    }

    return true;
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

    const Matrix<int> expected({
        { 3, 0, 0 },
        { 0, 0, 4 },
        { 9, 0, 0 }
        });

    assert(compare(matrix, expected));
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

    const Matrix<int> expected({
        { 1, 2 },
        { 3, 4 },
        { 5, 6 },
        { 5, 6 }
        });

    assert(compare(matrix, expected));
}

void testPolymorphicGenerator() {
    // Конструктор Exercise заполняет матрицу через Generator&,
    // при этом вызывается generate() производного класса.
    Matrix<int> counter(2, 2);
    CounterGenerator counterGenerator;
    Task1 counterTask(counter, counterGenerator);
    assert(compare(counter, Matrix<int>({ { 1, 2 }, { 3, 4 } })));

    Matrix<int> zeros(2, 2, 9);
    ZeroGenerator zeroGenerator;
    Task1 zeroTask(zeros, zeroGenerator);
    assert(compare(zeros, Matrix<int>(2, 2, 0)));

    Matrix<int> constant(2, 2);
    ConstantGenerator constantGenerator(7);
    Task2 constantTask(constant, constantGenerator);
    assert(compare(constant, Matrix<int>(2, 2, 7)));

    Matrix<int> random(2, 2);
    RandomGenerator randomGenerator(5, 5);
    Task1 randomTask(random, randomGenerator);
    assert(compare(random, Matrix<int>(2, 2, 5)));
}
