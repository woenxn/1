#pragma once

#include <vector>
#include <string>
#include <cstddef>

namespace miit::algebra {

    template<typename T>
    class Matrix {
    private:
        std::vector<std::vector<T>> data;
        std::size_t rows;
        std::size_t cols;

    public:
        Matrix();
        Matrix(const std::size_t rows, const std::size_t cols);
        Matrix(const std::size_t rows, const std::size_t cols, const T& value);
        Matrix(const std::vector<std::vector<T>>& data);

        Matrix(const Matrix& other) = default;
        Matrix(Matrix&& other) noexcept = default;
        ~Matrix() = default;

        Matrix& operator=(const Matrix& other) = default;
        Matrix& operator=(Matrix&& other) noexcept = default;
        Matrix& operator=(const std::vector<std::vector<T>>& data);

        std::vector<T>& operator[](const std::size_t index);
        const std::vector<T>& operator[](const std::size_t index) const;

        std::size_t getRows() const;
        std::size_t getCols() const;

        void resize(const std::size_t rows, const std::size_t cols, const T& value = T());
        void insertRowAfter(const std::size_t index, const std::vector<T>& row);
        void removeRow(const std::size_t index);
        void removeColumn(const std::size_t index);

        std::string toString() const;

        Matrix& operator<<(const std::size_t shift);
        Matrix& operator>>(const std::size_t shift);
    };

}
