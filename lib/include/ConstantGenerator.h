#pragma once

#include "Generator.h"

namespace miit::algebra {

    class ConstantGenerator : public Generator {
    private:
        int value;

    public:
        explicit ConstantGenerator(const int value);

        int generate() override;
    };

}
