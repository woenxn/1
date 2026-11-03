#pragma once

#include "Matrix.h"
#include "Generator.h"

namespace miit::algebra {

    /**
     * @brief Базовый класс для задач над матрицей.
     */
    class Exercise {
    protected:
        Matrix<int>& matrix;
        Generator& generator;

    public:
        /**
         * @brief Конструктор базового класса задач.
         * @param matrix Ссылка на матрицу.
         * @param generator Ссылка на генератор.
         */
        Exercise(Matrix<int>& matrix, Generator& generator);

        virtual ~Exercise() = default;

        /**
         * @brief Чисто виртуальный метод для решения задачи. Должен быть переопределен в наследниках.
         */
        virtual void solve() = 0;

        /**
         * @brief Заполняет матрицу с помощью связанного генератора.
         */
        void fill();
    };

}
