#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra {

    /**
     * @brief Генератор случайных чисел в заданном диапазоне.
     */
    class RandomGenerator : public Generator {
    private:
        std::uniform_int_distribution<int> distribution;
        std::mt19937 generator;

    public:
        /**
         * @brief Конструктор генератора случайных чисел.
         * @param min Минимальное значение диапазона (включительно).
         * @param max Максимальное значение диапазона (включительно).
         */
        RandomGenerator(const int min, const int max);

        /**
         * @brief Генерирует случайное число.
         * @return Случайное число в заданном диапазоне.
         */
        int generate() override;
    };

}
