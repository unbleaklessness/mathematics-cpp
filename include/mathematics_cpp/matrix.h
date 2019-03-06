#pragma once

#include "vector.h"

#define real float

/**
 * Indexing: ROWSxCOLUMNS = [C + R * COLUMNS]
 */
struct matrix {
    matrix(const size_t &rows, const size_t &columns);
    matrix(const size_t &rows, const size_t &columns, const real *data);

    void print() const;

    matrix operator*(const matrix &other) const;

    matrix set_column(const size_t &n, const matrix &column) const ;
    matrix set_row(const size_t &n, const matrix &row) const;

    matrix get_column(const size_t &n) const;
    matrix get_row(const size_t &n) const;

    size_t rows;
    size_t columns;

    real data[];
};

