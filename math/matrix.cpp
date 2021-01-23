#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * @title Matrix
 */

struct matrix {
public:
	std::vector<std::vector<long long>> v;
	matrix() = default;
	matrix(int N) {
		v = std::vector(N, std::vector(N, 0LL));
		for (int i = 0; i < N; i++)v[i][i] = 1;
	}
	matrix(int N, int M, long long x) {
		v = std::vector(N, std::vector(M, x));
	}
	matrix(std::initializer_list<std::initializer_list<long long>> list) {
		for (auto&& row : list) {
			v.push_back(row);
		}
	}

	int height() const { return v.size(); };
	int width() const { return v[0].size(); };

	matrix& operator=(std::initializer_list<std::initializer_list<long long>> list) {
		v.clear();
		for (auto&& row : list) {
			v.push_back(row);
		}
		return *this;
	}

	matrix& operator+= (const matrix& r) {
		for (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++) {
			v[i][j] += r.v[i][j];
		}
		return *this;
	}

	matrix& operator-= (const matrix& r) {
		for (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++) {
			v[i][j] -= r.v[i][j];
		}
		return *this;
	}

	matrix& operator*= (const matrix& r) {
		std::vector c(height(), std::vector(r.width(), 0LL));
		for (int i = 0; i < height(); i++) {
			for (int j = 0; j < r.width(); j++) {
				for (int k = 0; k < width(); k++) {
					c[i][j] += v[i][k] * r.v[k][j];
				}
			}
		}
		v = c;
		return *this;
	}

	void dump() {
		for (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++) {
			std::cout << v[i][j] << (j == width() - 1 ? "\n" : " ");
		}
	}
};

matrix operator+(const matrix& l, const matrix& r) { return matrix(l) += r; }
matrix operator-(const matrix& l, const matrix& r) { return matrix(l) -= r; }
matrix operator*(const matrix& l, const matrix& r) { return matrix(l) *= r; }
