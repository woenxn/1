#pragma once

#include "Exercise.h"

namespace miit::algebra {

    class Task2 : public Exercise {
    public:
        Task2(Matrix<int>& matrix, Generator& generator);
        void solve() override;

    private:
        bool rowContainsMaxAbs(const std::size_t row, const int maxAbs) const;
    };

}
