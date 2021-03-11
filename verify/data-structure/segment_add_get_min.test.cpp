#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include <bits/stdc++.h>
#include "data-structure/li_chao_tree.cpp"
using namespace std;
typedef long long ll;

constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
int main() {
    LiChaoTree<ll, -INF, INF> LCT;
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        LCT.add_segment(l, r, a, b);
    }
    for (int i = 0; i < Q; i++) {
        ll t;
        cin >> t;
        if (t == 0) {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            LCT.add_segment(l, r, a, b);
        }
        else {
            ll p;
            cin >> p;
            ll tmp = LCT.query(p);
            if (tmp == INF_LL)cout << "INFINITY" << endl;
            else cout << tmp << endl;
        }
    }
}