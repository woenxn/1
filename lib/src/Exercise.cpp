#include "Exercise.h"

namespace miit::algebra {

    Exercise::Exercise(Matrix<int>& matrix, Generator& generator)
        : matrix(matrix), generator(generator) {
    }

    void Exercise::fill() {
        const std::size_t rows = matrix.getRows();
        const std::size_t cols = matrix.getCols();

        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                matrix[i][j] = generator.generate();
            }
        }
    }

}
