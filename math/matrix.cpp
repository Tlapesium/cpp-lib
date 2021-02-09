#pragma once
#include <vector>
#include <initializer_list>
#include <iostream>

template <class T>
struct Matrix {
public:
	std::vector<std::vector<T>> v;
	Matrix() = default;
	Matrix(int N) {
		v = std::vector(N, std::vector(N, T(0)));
		for (int i = 0; i < N; i++)v[i][i] = T(1);
	}
	Matrix(int N, int M, T x) {
		v = std::vector(N, std::vector(M, x));
	}
	Matrix(std::initializer_list<std::initializer_list<long long>> list) {
		for (auto row : list) {
			v.push_back(std::vector<T>());
			for (auto x : row) {
				v.back().push_back(T(x));
			}
		}
	}

	int height() const { return v.size(); };
	int width() const { return v[0].size(); };

	Matrix& operator=(std::initializer_list<std::initializer_list<long long>> list) {
		v.clear();
		for (auto row : list) {
			v.push_back(std::vector<T>());
			for (auto x : row) {
				v.back().push_back(T(x));
			}
		}
		return *this;
	}

	Matrix& operator+= (const Matrix& r) {
		for (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++) {
			v[i][j] += r.v[i][j];
		}
		return *this;
	}

	Matrix& operator-= (const Matrix& r) {
		for (int i = 0; i < height(); i++)for (int j = 0; j < width(); j++) {
			v[i][j] -= r.v[i][j];
		}
		return *this;
	}

	Matrix& operator*= (const Matrix& r) {
		std::vector c(height(), std::vector(r.width(), T(0)));
		for (int i = 0; i < height(); i++) {
			for (int k = 0; k < width(); k++) {
				for (int j = 0; j < r.width(); j++) {
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
template <class T>
Matrix<T> operator+(const Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) += r; }
template <class T>
Matrix<T> operator-(const Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) -= r; }
template <class T>
Matrix<T> operator*(const Matrix<T>& l, const Matrix<T>& r) { return Matrix<T>(l) *= r; }
