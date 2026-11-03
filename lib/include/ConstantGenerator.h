#pragma once

#include "Generator.h"

namespace miit::algebra {

    /**
     * @brief Генератор, возвращающий заданную константу.
     */
    class ConstantGenerator : public Generator {
    private:
        int value;

    public:
        /**
         * @brief Конструктор генератора констант.
         * @param value значение, которое будет возвращаться.
         */
        explicit ConstantGenerator(const int value);

        /**
         * @brief Возвращает заданное константное значение.
         * @return Константное значение.
         */
        int generate() override;
    };

}
