#include "Task1.h"

namespace miit::algebra {

    Task1::Task1(Matrix<int>& matrix, Generator& generator)
        : Exercise(matrix, generator) {
    }

    void Task1::solve() {
        const std::size_t rows = matrix.getRows();
        const std::size_t cols = matrix.getCols();

        if (rows == 0 || cols == 0) {
            return;
        }

        for (std::size_t j = 0; j < cols; ++j) {
            int minValue = matrix[0][j];

            for (std::size_t i = 1; i < rows; ++i) {
                if (matrix[i][j] < minValue) {
                    minValue = matrix[i][j];
                }
            }

            for (std::size_t i = 0; i < rows; ++i) {
                if (matrix[i][j] == minValue) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

}
