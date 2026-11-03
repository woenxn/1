#include <cassert>

#include "Matrix.h"
#include "Task1.h"
#include "Task2.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

void testTask1() {
    Matrix<int> matrix({
        { 3, -5, 2 },
        { 1, -5, 4 },
        { 9,  0, 2 }
        });

    ConstantGenerator generator(0);
    Task1 task(matrix, generator);
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
    Matrix<int> matrix({
        { 1, 2 },
        { 3, 4 },
        { 5, 6 }
        });

    ConstantGenerator generator(0);
    Task2 task(matrix, generator);
    task.solve();

    assert(matrix.getRows() == 4);
    assert(matrix[3][0] == 5);
    assert(matrix[3][1] == 6);
}

int main() {
    testTask1();
    testTask2();

    return 0;
}
