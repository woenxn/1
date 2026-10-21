#pragma once

#include "Generator.h"

namespace miit::algebra {

    class ZeroGenerator : public Generator {
    public:
        int generate() override {
            return 0;
        }
    };

}
