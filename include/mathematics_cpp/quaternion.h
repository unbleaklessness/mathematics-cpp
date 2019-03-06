#pragma "once"

#include "matrix.h"
#include "vector.h"

#define real float

struct quaternion {
    quaternion(const real &w, const real &x, const real &y, const real &z);
    explicit quaternion(const vector<3> &v);

    static quaternion from_euler(const vector<3> &v);

    matrix<3, 3> to_matrix3() const;
    matrix<4, 4> to_matrix4() const;

    vector<3> operator*(const vector<3> &v) const;
    quaternion operator*(const quaternion &other) const;

    vector<3> to_vector3() const;
    vector<3> to_euler() const;

    quaternion conjugate() const;

    real w;
    real x;
    real y;
    real z;

    void print() const;
};

