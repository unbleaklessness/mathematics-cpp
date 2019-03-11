#include "quaternion.h"

#include <cmath>
#include <iostream>

quaternion::quaternion(const real &w, const real &x, const real &y, const real &z) {
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

quaternion::quaternion(const vector<3> &v) {
    this->w = 0;
    this->x = v[0];
    this->y = v[1];
    this->z = v[2];
}

matrix quaternion::to_matrix3() const {
    const real data[9] = {
            w * w + x * x - y * y - z * z, 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y,
            2 * x * y + 2 * w * z, w * w - x * x + y * y - z * z, 2 * y * z + 2 * w * x,
            2 * x * z - 2 * w * y, 2 * y * z - 2 * w * x, w * w - x * x - y * y + z * z
    };
    return matrix(3, 3, data);
}

matrix quaternion::to_matrix4() const {
    const real data[16] = {
            w * w + x * x - y * y - z * z, 2 * x * y - 2 * w * z, 2 * x * z + 2 * w * y, 0,
            2 * x * y + 2 * w * z, w * w - x * x + y * y - z * z, 2 * y * z + 2 * w * x, 0,
            2 * x * z - 2 * w * y, 2 * y * z - 2 * w * x, w * w - x * x - y * y + z * z, 0,
            0, 0, 0, 1
    };
    return matrix(4, 4, data);
}

quaternion quaternion::conjugate() const {
    return quaternion {w, -x, -y, -z};
}

vector<3> quaternion::operator*(const vector<3> &v) const {
    auto result = (*this) * quaternion(v) * conjugate();
    return result.to_vector3();
}

quaternion quaternion::operator*(const quaternion &other) const {
    return quaternion {
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
    };
}

vector<3> quaternion::to_vector3() const {
    return vector<3> {x, y, z};
}

vector<3> quaternion::to_euler() const {
    real x = this->w;
    real y = this->x;
    real z = this->y;
    real w = this->z;
    real t0 = 2.0 * (w * x + y * z);
    real t1 = 1.0 - 2.0 * (x * x + y * y);
    real roll = atan2(t0, t1);
    real t2 = 2.0 * (w * y - z * x);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    real pitch = asin(t2);
    real t3 = 2.0 * (w * z + x * y);
    real t4 = 1.0 - 2.0 * (y * y + z * z);
    real yaw = atan2(t3, t4);
    return vector<3> { yaw, pitch, roll };
}

void quaternion::print() const {
    std::cout << "(" << w << " " << x << " " << y << " " << z << ")" << std::endl;
}

quaternion quaternion::from_euler(const vector<3> &v) {
    return quaternion {
            sin(v[2] / 2) * cos(v[1] / 2) * cos(v[0] / 2) - cos(v[2] / 2) * sin(v[1] / 2) * sin(v[0] / 2),
            cos(v[2] / 2) * sin(v[1] / 2) * cos(v[0] / 2) + sin(v[2] / 2) * cos(v[1] / 2) * sin(v[0] / 2),
            cos(v[2] / 2) * cos(v[1] / 2) * sin(v[0] / 2) - sin(v[2] / 2) * sin(v[1] / 2) * cos(v[0] / 2),
            cos(v[2] / 2) * cos(v[1] / 2) * cos(v[0] / 2) + sin(v[2] / 2) * sin(v[1] / 2) * sin(v[0] / 2)
    };
}