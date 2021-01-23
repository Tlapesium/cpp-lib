#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * @title Matrix
 */

struct matrix {
	std::vector<std::vector<long long>> v;
	matrix() = default;
	matrix(int N, int M) {
		v = std::vector(N, std::vector(M, 0LL));
	}

	matrix(std::initializer_list<std::initializer_list<long long>> list) {
		for (auto&& row : list) {
			v.push_back(row);
		}
	}
	matrix& operator=(std::initializer_list<std::initializer_list<long long>> list) {
		this->v.clear();
		for (auto&& row : list) {
			this->v.push_back(row);
		}
		return *this;
	}

	matrix& operator+= (const matrix& r) {
		for (int i = 0; i < v.size(); i++)for (int j = 0; j < v[i].size(); j++) {
			v[i][j] += r.v[i][j];
		}
		return *this;
	}

	matrix& operator-= (const matrix& r) {
		for (int i = 0; i < v.size(); i++)for (int j = 0; j < v[i].size(); j++) {
			v[i][j] -= r.v[i][j];
		}
		return *this;
	}

	matrix& operator*= (const matrix& r) {
		std::vector c(v.size(), std::vector(r.v[0].size(), 0LL));
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < r.v[0].size(); j++) {
				for (int k = 0; k < v[0].size(); k++) {
					c[i][j] += v[i][k] * r.v[k][j];
				}
			}
		}
		v = c;
		return *this;
	}

	void dump() {
		for (int i = 0; i < v.size(); i++)for (int j = 0; j < v[i].size(); j++) {
			std::cout << v[i][j] << (j == v[i].size() - 1 ? "\n" : " ");
		}
	}
};

matrix operator+(const matrix& l, const matrix& r) { return matrix(l) += r; }
matrix operator-(const matrix& l, const matrix& r) { return matrix(l) -= r; }
matrix operator*(const matrix& l, const matrix& r) { return matrix(l) *= r; }

