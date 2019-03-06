#pragma once

#include <vector>
#include <functional>

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
