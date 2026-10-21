#include "Task2.h"

#include <cstdlib>
#include <vector>

namespace miit::algebra {

    Task2::Task2(Matrix<int>& matrix, Generator& generator)
        : Exercise(matrix, generator) {
    }

    bool Task2::rowContainsMaxAbs(const std::size_t row, const int maxAbs) const {
        const std::size_t cols = matrix.getCols();

        for (std::size_t j = 0; j < cols; ++j) {
            if (std::abs(matrix[row][j]) == maxAbs) {
                return true;
            }
        }

        return false;
    }

    void Task2::solve() {
        const std::size_t originalRows = matrix.getRows();
        const std::size_t cols = matrix.getCols();

        if (originalRows == 0 || cols == 0) {
            return;
        }

        int maxAbs = std::abs(matrix[0][0]);

        for (std::size_t i = 0; i < originalRows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                const int currentAbs = std::abs(matrix[i][j]);

                if (currentAbs > maxAbs) {
                    maxAbs = currentAbs;
                }
            }
        }

        const std::vector<int> lastRow = matrix[originalRows - 1];
        std::size_t insertIndex = 0;

        for (std::size_t i = 0; i < originalRows; ++i) {
            if (rowContainsMaxAbs(insertIndex, maxAbs)) {
                matrix.insertRowAfter(insertIndex, lastRow);
                insertIndex += 2;
            }
            else {
                ++insertIndex;
            }
        }
    }

}
