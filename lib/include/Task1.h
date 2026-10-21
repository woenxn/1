#pragma once

#include "Exercise.h"

namespace miit::algebra {

    class Task1 : public Exercise {
    public:
        Task1(Matrix<int>& matrix, Generator& generator);
        void solve() override;
    };

}
