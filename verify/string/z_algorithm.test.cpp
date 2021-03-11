#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <bits/stdc++.h>
#include "string/z_algorithm.cpp"
using namespace std;
typedef long long ll;

int main() {
	string S;
	cin >> S;
	auto v = z_algorithm(S);
	for (int i = 0; i < v.size(); i++)cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
}