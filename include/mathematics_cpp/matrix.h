#pragma once

#include <cstdlib>
#include <vector>

#define real float

/**
 * Indexing: ROWSxCOLUMNS = [C + R * COLUMNS]
 */
class matrix {
public:
    /**
     * Create a matrix initialized with zeros.
     * @param rows Number of rows.
     * @param columns Number of columns.
     */
    matrix(size_t rows, size_t columns);

    /**
     * Create a matrix from given data array. Number of elements in data array should equal `rows * columns`.
     * @param rows Number of rows for new matrix.
     * @param columns Number of columns for new matrix.
     * @param data Data array.
     */
    matrix(size_t rows, size_t columns, const real *data);

    ~matrix() {
        delete data;
    }

    /**
     * Prints out this matrix.
     */
    void print() const;

    /**
     * Multiply this matrix on given matrix.
     * @param other Other matrix.
     * @return Result of multiplication, new matrix.
     */
    matrix operator*(const matrix &other) const;

    /**
     * Get the value of the matrix element at given row-column index.
     * @param row Row.
     * @param column Column.
     * @return Reference to the matrix element.
     */
    real &get(size_t row, size_t column) { return data[column + row * columns]; }

    /**
     * Get the value of the matrix element at given row-column index.
     * @param row Row.
     * @param column Column.
     * @return Constant reference to the matrix element.
     */
    const real &get(size_t row, size_t column) const { return data[column + row * columns]; }

    /**
     * Get number of rows.
     * @return Number of rows.
     */
    size_t get_rows() const { return rows; }

    /**
     * Get number of columns.
     * @return Number of columns.
     */
    size_t get_columns() const { return columns; }

    /**
     * Create a matrix from given `std::vector<real>`. Number of elements in the vector should match `rows * columns` of
     * the matrix. Throws `std::runtime_error` if this condition is false.
     * @param rows Number of rows for new matrix.
     * @param columns Number of columns for new matrix.
     * @param vector Input vector.
     * @return Resulting matrix.
     */
    static matrix from_std_vector(size_t rows, size_t columns, const std::vector<real> &vector);

    bool operator==(const matrix &other) const;

private:
    size_t rows;
    size_t columns;

    real *data;
};

