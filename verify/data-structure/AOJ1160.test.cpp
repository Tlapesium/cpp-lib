#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1160"
#include <bits/stdc++.h>
#include "data-structure/union_find.cpp"
using namespace std;
typedef long long ll;

int main() {
	int dx[] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 }, dy[] = { 1, 0, -1, 1, 0, -1, 1, 0, -1 };
	while (1) {
		int W, H;
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		vector grid(H + 2, vector(W + 2, 0));
		for (int i = 0; i < H; i++)for (int j = 0; j < W; j++) {
			cin >> grid[i + 1][j + 1];
		}
		UnionFind uf((H + 2) * (W + 2));
		for (int i = 1; i <= H; i++)for (int j = 1; j <= W; j++) {
			for (int k = 0; k < 9; k++) {
				if (grid[i][j] && grid[i + dy[k]][j + dx[k]]) {
					uf.merge(i * W + j, (i + dy[k]) * W + j + dx[k]);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < H + 2; i++)for (int j = 0; j < W + 2; j++)if (!grid[i][j])cnt++;
		cout << uf.forest_size() - cnt << endl;
	}
}