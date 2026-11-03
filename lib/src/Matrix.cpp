#include "Matrix.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>

namespace miit::algebra {

    template<typename T>
    Matrix<T>::Matrix()
        : rows(0), cols(0) {
    }

    template<typename T>
    Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)
        : data(rows, std::vector<T>(cols, T())), rows(rows), cols(cols) {
    }

    template<typename T>
    Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols, const T& value)
        : data(rows, std::vector<T>(cols, value)), rows(rows), cols(cols) {
    }

    template<typename T>
    Matrix<T>::Matrix(const std::vector<std::vector<T>>& data)
        : data(data), rows(data.size()), cols(data.empty() ? 0 : data[0].size()) {
        for (const auto& row : data) {
            if (row.size() != cols) {
                throw std::invalid_argument("Matrix rows have different sizes");
            }
        }
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const std::vector<std::vector<T>>& data) {
        this->data = data;
        this->rows = data.size();
        this->cols = data.empty() ? 0 : data[0].size();

        for (const auto& row : data) {
            if (row.size() != cols) {
                throw std::invalid_argument("Matrix rows have different sizes");
            }
        }

        return *this;
    }

    template<typename T>
    std::vector<T>& Matrix<T>::operator[](const std::size_t index) {
        return data.at(index);
    }

    template<typename T>
    const std::vector<T>& Matrix<T>::operator[](const std::size_t index) const {
        return data.at(index);
    }

    template<typename T>
    std::size_t Matrix<T>::getRows() const {
        return rows;
    }

    template<typename T>
    std::size_t Matrix<T>::getCols() const {
        return cols;
    }

    template<typename T>
    void Matrix<T>::resize(const std::size_t rows, const std::size_t cols, const T& value) {
        data.assign(rows, std::vector<T>(cols, value));
        this->rows = rows;
        this->cols = cols;
    }

    template<typename T>
    void Matrix<T>::insertRowAfter(const std::size_t index, const std::vector<T>& row) {
        if (index >= rows) {
            throw std::out_of_range("insertRowAfter: index out of range");
        }

        if (row.size() != cols) {
            throw std::invalid_argument("insertRowAfter: row size mismatch");
        }

        data.insert(data.begin() + index + 1, row);
        ++rows;
    }

    template<typename T>
    void Matrix<T>::removeRow(const std::size_t index) {
        if (index >= rows) {
            throw std::out_of_range("removeRow: index out of range");
        }

        data.erase(data.begin() + index);
        --rows;
    }

    template<typename T>
    void Matrix<T>::removeColumn(const std::size_t index) {
        if (index >= cols) {
            throw std::out_of_range("removeColumn: index out of range");
        }

        for (auto& row : data) {
            row.erase(row.begin() + index);
        }

        --cols;
    }

    template<typename T>
    std::string Matrix<T>::toString() const {
        std::ostringstream oss;

        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < cols; ++j) {
                oss << data[i][j];
                if (j + 1 < cols) {
                    oss << ' ';
                }
            }
            oss << '\n';
        }

        return oss.str();
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator<<(const std::size_t shift) {
        if (cols == 0) {
            return *this;
        }

        const std::size_t normalizedShift = shift % cols;

        for (auto& row : data) {
            std::rotate(row.begin(), row.begin() + normalizedShift, row.end());
        }

        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator>>(const std::size_t shift) {
        if (cols == 0) {
            return *this;
        }

        const std::size_t normalizedShift = shift % cols;

        for (auto& row : data) {
            std::rotate(row.begin(), row.end() - normalizedShift, row.end());
        }

        return *this;
    }

    template class Matrix<int>;

}
