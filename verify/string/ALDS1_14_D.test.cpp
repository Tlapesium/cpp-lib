#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D"
#include "string/suffix_array.cpp"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string S;
	cin >> S;
	SuffixArray SA(S);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		string t;
		cin >> t;
		auto range = SA.get_range(t);
		cout << (range.first != range.second) << endl;
	}
}