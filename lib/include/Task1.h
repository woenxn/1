#pragma once

#include "Exercise.h"

namespace miit::algebra {

    /**
     * @brief Задача 1: Заменить минимальный элемент каждого столбца нулем.
     */
    class Task1 : public Exercise {
    public:
        /**
         * @brief Конструктор задачи 1.
         * @param matrix ссылка на матрицу.
         * @param generator ссылка на генератор.
         */
        Task1(Matrix<int>& matrix, Generator& generator);

        /**
         * @brief Выполняет решение задачи 1.
         */
        void solve() override;
    };

}
