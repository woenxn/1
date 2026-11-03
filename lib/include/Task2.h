#pragma once

#include "Exercise.h"

namespace miit::algebra {

    /**
     * @brief Задача 2: Вставить после каждой строки, содержащей максимальный по модулю элемент, последнюю строку.
     */
    class Task2 : public Exercise {
    public:
        /**
         * @brief Конструктор задачи 2.
         * @param matrix ссылка на матрицу.
         * @param generator ссылка на генератор.
         */
        Task2(Matrix<int>& matrix, Generator& generator);

        /**
         * @brief Выполняет решение задачи 2.
         */
        void solve() override;

    private:
        /**
         * @brief Вспомогательный метод: проверяет, содержит ли строка максимальный по модулю элемент.
         * @param row индекс проверяемой строки.
         * @param maxAbs максимальное по модулю значение в матрице.
         * @return true, если содержит, иначе false.
         */
        bool rowContainsMaxAbs(const std::size_t row, const int maxAbs) const;
    };

}
