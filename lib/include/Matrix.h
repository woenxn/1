#pragma once

#include <vector>
#include <string>
#include <cstddef>

namespace miit::algebra {

    /**
     * @brief Шаблонный класс для представления двумерного массива.
     * @tparam T Тип элементов матрицы.
     */
    template<typename T>
    class Matrix {
    private:
        std::vector<std::vector<T>> data;
        std::size_t rows;
        std::size_t cols;

    public:
        /**
         * @brief Конструктор по умолчанию. Создает пустую матрицу 0x0.
         */
        Matrix();

        /**
         * @brief Конструктор, создающий матрицу заданного размера, заполненную значениями по умолчанию.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         */
        Matrix(const std::size_t rows, const std::size_t cols);

        /**
         * @brief Конструктор, создающий матрицу заданного размера с заданным значением.
         * @param rows Количество строк.
         * @param cols Количество столбцов.
         * @param value Значение для заполнения.
         */
        Matrix(const std::size_t rows, const std::size_t cols, const T& value);

        /**
         * @brief Конструктор из двумерного вектора.
         * @param data Двумерный вектор.
         * @throw std::invalid_argument Если строки имеют разную длину.
         */
        Matrix(const std::vector<std::vector<T>>& data);

        Matrix(const Matrix& other) = default;
        Matrix(Matrix&& other) noexcept = default;
        ~Matrix() = default;

        Matrix& operator=(const Matrix& other) = default;
        Matrix& operator=(Matrix&& other) noexcept = default;

        /**
         * @brief Оператор присваивания из двумерного вектора.
         * @param data Двумерный вектор.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator=(const std::vector<std::vector<T>>& data);

        /**
         * @brief Оператор доступа к строке по индексу.
         * @param index Индекс строки.
         * @return Ссылка на вектор элементов строки.
         */
        std::vector<T>& operator[](const std::size_t index);

        /**
         * @brief Оператор доступа к строке по индексу (только для чтения).
         * @param index Индекс строки.
         * @return Константная ссылка на вектор элементов строки.
         */
        const std::vector<T>& operator[](const std::size_t index) const;

        /**
         * @brief Получить количество строк.
         * @return Количество строк.
         */
        std::size_t getRows() const;

        /**
         * @brief Получить количество столбцов.
         * @return Количество столбцов.
         */
        std::size_t getCols() const;

        /**
         * @brief Изменить размер матрицы и заполнить её заданным значением.
         * @param rows Новое количество строк.
         * @param cols Новое количество столбцов.
         * @param value Значение для заполнения.
         */
        void resize(const std::size_t rows, const std::size_t cols, const T& value = T());

        /**
         * @brief Вставить строку после заданного индекса.
         * @param index Индекс строки, после которой нужно вставить.
         * @param row Вставляемая строка.
         * @throw std::out_of_range Если индекс за пределами матрицы.
         * @throw std::invalid_argument Если размер вставляемой строки не совпадает с шириной матрицы.
         */
        void insertRowAfter(const std::size_t index, const std::vector<T>& row);

        /**
         * @brief Удалить строку по индексу.
         * @param index Индекс удаляемой строки.
         * @throw std::out_of_range Если индекс за пределами матрицы.
         */
        void removeRow(const std::size_t index);

        /**
         * @brief Удалить столбец по индексу.
         * @param index Индекс удаляемого столбца.
         * @throw std::out_of_range Если индекс за пределами матрицы.
         */
        void removeColumn(const std::size_t index);

        /**
         * @brief Преобразовать матрицу в строковое представление.
         * @return Строка, содержащая элементы матрицы.
         */
        std::string toString() const;

        /**
         * @brief Оператор сдвига элементов строк влево (циклический).
         * @param shift Количество позиций для сдвига.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator<<(const std::size_t shift);

        /**
         * @brief Оператор сдвига элементов строк вправо (циклический).
         * @param shift Количество позиций для сдвига.
         * @return Ссылка на текущую матрицу.
         */
        Matrix& operator>>(const std::size_t shift);
    };

}
