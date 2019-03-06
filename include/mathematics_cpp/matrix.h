#pragma once

#include "vector.h"

#define real float

/**
 * Indexing: RxC = [C + R * COLUMNS]
 */
template<size_t R, size_t C>
struct matrix {
    matrix();
    explicit matrix(const real *data);

    void print() const;

    vector<R> operator*(const vector<C> &other) const;

    matrix<R, C> set_column(size_t n, const vector<R> &column) const ;
    matrix<R, C> set_row(size_t n, const vector<C> &row) const;

    vector<R> get_column(size_t n) const;
    vector<C> get_row(size_t n) const;

    size_t rows = R;
    size_t columns = C;

    real data[R * C] {};
};


