#include "matrix.h"

#include <iostream>
#include <matrix.h>


matrix::matrix(size_t rows, size_t columns) {
    for (size_t i = 0; i < rows * columns; i++) {

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
