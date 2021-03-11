#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "string/suffix_array.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string S;
	cin >> S;
	SuffixArray SA(S);
	SA.dump();
}