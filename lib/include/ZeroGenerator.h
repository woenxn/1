#pragma once

#include "Generator.h"

namespace miit::algebra {

    /**
     * @brief Генератор, который всегда возвращает нули.
     */
    class ZeroGenerator : public Generator {
    public:
        /**
         * @brief Возвращает ноль.
         * @return Всегда 0.
         */
        int generate() override {
            return 0;
        }
    };

}
