#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra {

    /**
     * @brief Генератор, читающий числа из входного потока.
     */
    class IStreamGenerator : public Generator {
    private:
        std::istream& in;

    public:
        /**
         * @brief Конструктор генератора на основе потока.
         * @param in Ссылка на входной поток.
         */
        explicit IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Читает число из потока.
         * @return Прочитанное число.
         */
        int generate() override;
    };

}
