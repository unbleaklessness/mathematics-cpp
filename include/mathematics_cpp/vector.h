#pragma once

#include <vector>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <cmath>

#define real float

template<size_t N>
struct vector {
	vector();
	vector(const vector &other);
	vector(const real &number);
	vector(std::initializer_list<real> arguments);

	void print() const;
	void normalize();
	real length() const;
    vector<N> map(std::function<real(real)> f) const;

	vector<N> &operator=(const vector<N> &other);

	vector<N> operator+(const vector<N> &other) const;
	vector<N> operator-(const vector<N> &other) const;
	vector<N> operator*(const vector<N> &other) const;

	vector<N> &operator+=(const vector<N> &other);
    vector<N> &operator-=(const vector<N> &other);
	vector<N> &operator*=(const vector<N> &other);
	vector<N> &operator/=(const vector<N> &other);

    vector<N> operator*(const real &number) const;

	vector<N> &operator/=(const real &number);

	bool operator==(const vector<N> &other) const;

	real operator[](const size_t &i) const;
	real &operator[](const size_t &i);

	std::vector<real> to_std_vector();

    real data[N];
};

using vector1 = vector<1>;
using vector2 = vector<2>;
using vector3 = vector<3>;
using vector4 = vector<4>;

template<size_t N>
vector<N>::vector() {
	for (size_t i = 0; i < N; i++) {
		data[i] = 0.0f;
	}
}

template<size_t N>
vector<N>::vector(const real &number) {
	for (size_t i = 0; i < N; i++) {
		data[i] = number;
	}
}

template<size_t N>
vector<N>::vector(std::initializer_list<real> arguments) {
	if (arguments.size() != N) {
		throw std::runtime_error("ERROR: Initializer list for `vector` class received wrong number of arguments!");
	}
	size_t i = 0;
	for (auto it = arguments.begin(); it != arguments.end(); ++it, i++) {
		data[i] = *it;
	}
}

template<size_t N>
vector<N> vector<N>::operator+(const vector<N> &other) const {
	vector<N> result;
	for (size_t i = 0; i < N; i++) {
		result = data[i] + other.data[i];
	}
	return result;
}

template<size_t N>
vector<N> vector<N>::operator-(const vector<N> &other) const {
	vector<N> result;
	for (size_t i = 0; i < N; i++) {
		result = data[i] - other.data[i];
	}
	return result;
}

template<size_t N>
vector<N> vector<N>::operator*(const vector<N> &other) const {
	vector<N> result(1.0f);
	for (size_t i = 0; i < N; i++) {
		result = data[i] * other.data[i];
	}
	return result;
}

template<size_t N>
vector<N> &vector<N>::operator+=(const vector<N> &other) {
	for (size_t i = 0; i < N; i++) {
		data[i] += other.data[i];
	}
	return *this;
}

template<size_t N>
vector<N> &vector<N>::operator-=(const vector<N> &other) {
	for (size_t i = 0; i < N; i++) {
		data[i] -= other.data[i];
	}
	return *this;
}

template<size_t N>
vector<N> &vector<N>::operator*=(const vector<N> &other) {
	for (size_t i = 0; i < N; i++) {
		data[i] *= other.data[i];
	}
	return *this;
}

template<size_t N>
vector<N> &vector<N>::operator/=(const vector<N> &other) {
	for (size_t i = 0; i < N; i++) {
		data[i] /= other.data[i];
	}
	return *this;
}

template<size_t N>
vector<N> & vector<N>::operator/=(const real &number) {
	for (size_t i = 0; i < N; i++) {
		data[i] /= number;
	}
	return *this;
}

template<size_t N>
bool vector<N>::operator==(const vector<N> &other) const {
	for (size_t i = 0; i < N; i++) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}

template<size_t N>
real vector<N>::operator[](const size_t &i) const {
	return data[i];
}

template<size_t N>
real &vector<N>::operator[](const size_t &i) {
	return data[i];
}

template<size_t N>
void vector<N>::print() const {
	std::cout << " (";
	for (size_t i = 0; i < N; i++) {
		if (i != N - 1) {
			std::cout << data[i] << ", ";
		} else {
			std::cout << data[i];
		}
	}
	std::cout << ") ";
}

template<size_t N>
vector<N> &vector<N>::operator=(const vector<N> &other) {
	if (this != &other) {
		for (size_t i = 0; i < N; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template<size_t N>
vector<N>::vector(const vector &other) {
	for (size_t i = 0; i < N; i++) {
		data[i] = other.data[i];
	}
}

template<size_t N>
void vector<N>::normalize() {
	real len = length();
	for (size_t i = 0; i < N; i++) {
		data[i] /= len;
	}
}

template<size_t N>
real vector<N>::length() const {
	real len = 0;
	for (size_t i = 0; i < N; i++) {
		len += powf(data[i], 2.0f);
	}
	return sqrtf(len);
}

template<size_t N>
vector<N> vector<N>::map(std::function<real(real)> f) const {
	vector<N> result;
	for (size_t i = 0; i < N; i++) {
		result[i] = f(data[i]);
	}
	return result;
}

template<size_t N>
vector<N> vector<N>::operator*(const real &number) const {
	vector<N> result;
	for (size_t i = 0; i < N; i++) {
		result[i] = data[i] * number;
	}
	return result;
}

template<size_t N>
std::vector<real> vector<N>::to_std_vector() {
	std::vector<real> result;
	for (size_t i = 0; i < N; i++) {
		result.push_back(data[i]);
	}
	return result;
}