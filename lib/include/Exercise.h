#pragma once

#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra {

    class Exercise {
    protected:
        Matrix<int>& matrix;
        Generator& generator; 

    public:
        Exercise(Matrix<int>& matrix, Generator& generator);
        virtual ~Exercise() = default;

        virtual void solve() = 0;

        void fill();
    };

}
