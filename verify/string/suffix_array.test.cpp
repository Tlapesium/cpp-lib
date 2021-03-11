#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <bits/stdc++.h>
#include "string/suffix_array.cpp"
using namespace std;
typedef long long ll;

int main() {
	string S;
	cin >> S;
	SuffixArray SA(S);
	SA.dump();
}