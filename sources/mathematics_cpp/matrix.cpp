#include "matrix.h"

#include <iostream>

matrix::matrix(size_t rows, size_t columns) {
    data = new real[rows * columns]();
    this->rows = rows;
    this->columns = columns;
}

matrix::matrix(size_t rows, size_t columns, const real *data) {
    if (data == nullptr) {
        throw std::runtime_error("Error from `matrix::matrix`, data array is `nullptr`.");
    }

    data = new real[rows * columns]();
    this->rows = rows;
    this->columns = columns;

    for (size_t i = 0; i < rows * columns; i++) {
        this->data[i] = data[i];
    }
}

void matrix::print() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

matrix matrix::operator*(const matrix &other) const {
    if (columns != other.rows) {
        throw std::runtime_error("Matrix multiplication error: wrong matrix dimensions.");
    }

    matrix result(rows, other.columns);

    for (size_t i = 0; i < result.rows; i++) {
        for (size_t j = 0; j < result.columns; j++) {
            for (size_t k = 0; k < columns; k++) {
                result.data[j + i * result.columns] += data[k + i * columns] * other.data[j + k * other.columns];
            }
        }
    }

    return result;
}

matrix matrix::from_std_vector(size_t rows, size_t columns, const std::vector<real> &vector) {
    if (vector.size() != rows * columns) {
        throw std::runtime_error("Error in `matrix::from_std_vector`, size of the `std::vector` is not equal `rows * columns`.");
    }

    auto result = matrix(rows, columns);

    for (size_t i = 0; i < rows * columns; i++) {
        result.data[i] = vector[i];
    }

    return result;
}

bool matrix::operator==(const matrix &other) const {
    if (rows != other.rows ||
        columns != other.columns)
    {
        return false;
    }

    for (size_t i = 0; i < rows * columns; i++) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

