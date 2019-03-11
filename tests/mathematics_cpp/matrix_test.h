#pragma once

#include <vector>

#include "matrix.h"
#include "gtest/gtest.h"

TEST(Matrix_test, Multiplication_1) {

    matrix m1 = matrix::from_std_vector(3, 3, std::vector<float> {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    });

    matrix m2 = matrix::from_std_vector(3, 3, std::vector<float> {
            9, 8, 7,
            6, 5, 4,
            3, 2, 1
    });

    matrix result = m1 * m2;

    matrix expected = matrix::from_std_vector(3, 3, std::vector<float> {
        30, 24, 18,
        84, 69, 54,
        138, 114, 90
    });

    ASSERT_EQ(true, result == expected);
}