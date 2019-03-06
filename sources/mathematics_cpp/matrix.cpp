#include "matrix.h"

#include <stddef.h>
#include <iostream>
#include <iomanip>

template<size_t R, size_t C>
matrix<R, C>::matrix() {
    for (size_t i = 0; i < R * C; i++) {
        data[i] = 0.0;
    }
}

template<size_t R, size_t C>
matrix<R, C>::matrix(const real *data) {
    for (size_t i = 0; i < R * C; i++) {
        this->data[i] = data[i];
    }
}

template<size_t R, size_t C>
vector<R> matrix<R, C>::operator*(const vector<C> &other) const {
    vector<R> result;
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            result[i] += data[i + j * columns] * other[j];
        }
    }
    return result;
}

template<size_t R, size_t C>
void matrix<R, C>::print() const {
    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            std::cout << std::fixed  << std::setprecision(4) << data[j + i * C] << "   ";
        }
        std::cout << std::endl;
    }
}

template<size_t R, size_t C>
matrix<R, C> matrix<R, C>::set_column(size_t n, const vector<R> &column) const {
    matrix<R, C> result(data);
    for (size_t i = 0; i < R; i++) {
        result.data[n + i * columns] = column[i];
    }
    return result;
}

template<size_t R, size_t C>
matrix<R, C> matrix<R, C>::set_row(size_t n, const vector<C> &row) const {
    matrix<R, C> result(data);
    for (size_t i = 0; i < C; i++) {
        result.data[i + n * columns] = row[i];
    }
    return result;
}

template<size_t R, size_t C>
vector<R> matrix<R, C>::get_column(size_t n) const {
    vector<R> result;
    for (size_t i = 0; i < R; i++) {
        result[i] = data[n + i * columns];
    }
    return result;
}

template<size_t R, size_t C>
vector<C> matrix<R, C>::get_row(size_t n) const {
    vector<R> result;
    for (size_t i = 0; i < R; i++) {
        result[i] = data[i + n * columns];
    }
    return result;
}