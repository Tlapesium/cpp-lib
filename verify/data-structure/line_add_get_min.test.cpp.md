---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/li_chao_tree.cpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/data-structure/line_add_get_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n#line 2 \"data-structure/li_chao_tree.cpp\"\
    \n#include <limits>\r\n#include <algorithm>\r\n#include <utility>\r\n\r\ntemplate<class\
    \ T, T x_min, T x_max, T inf = std::numeric_limits<T>::max()>\r\nstruct LiChaoTree\
    \ {\r\n    struct Line {\r\n        T a, b;\r\n        Line(T a, T b) : a(a),\
    \ b(b) {}\r\n        T operator() (T x) { return x * a + b; }\r\n    };\r\n  \
    \  struct Node {\r\n        Line line;\r\n        Node* l, * r;\r\n        Node(const\
    \ Line& x) : line(x), l(nullptr), r(nullptr) {};\r\n    };\r\n    Node* root;\r\
    \n    LiChaoTree() : root(nullptr) { }\r\n\r\n    Node* add_line(Node* node, Line\
    \ line, T l, T r) {\r\n        if (!node)return new Node(line);\r\n\r\n      \
    \  T m = (l + r) / 2;\r\n        if (m == r)m--;\r\n        T node_l = node->line(l),\
    \ node_m = node->line(m), node_r = node->line(r);\r\n        T line_l = line(l),\
    \ line_m = line(m), line_r = line(r);\r\n\r\n        if (node_l <= line_l && node_r\
    \ <= line_r) return node;\r\n        else if (node_l >= line_l && node_r >= line_r)\
    \ {\r\n            node->line = line;\r\n            return node;\r\n        }\r\
    \n        else {\r\n            if (node_m > line_m) {\r\n                std::swap(node->line,\
    \ line);\r\n                if (line_l >= node_l) node->l = add_line(node->l,\
    \ line, l, m);\r\n                else node->r = add_line(node->r, line, m + 1,\
    \ r);\r\n            }\r\n            else {\r\n                if (node_l >=\
    \ line_l) node->l = add_line(node->l, line, l, m);\r\n                else node->r\
    \ = add_line(node->r, line, m + 1, r);\r\n            }\r\n            return\
    \ node;\r\n        }\r\n    }\r\n\r\n    Node* add_segment(Node* node, Line line,\
    \ T a, T b, T l, T r) {\r\n        if (r < a || b < l)return node;\r\n       \
    \ if (a <= l && r <= b)return add_line(node, line, l, r);\r\n        if (node)\
    \ {\r\n            if (node->line(l) <= line(l) && node->line(r) <= line(r))return\
    \ node;\r\n        }\r\n        else node = new Node(Line(0, inf));\r\n      \
    \  T m = (l + r) / 2;\r\n        if (m == r)m--;\r\n        node->l = add_segment(node->l,\
    \ line, a, b, l, m);\r\n        node->r = add_segment(node->r, line, a, b, m +\
    \ 1, r);\r\n        return node;\r\n    }\r\n\r\n    T query(Node* node, T l,\
    \ T r, T x) {\r\n        if (!node)return inf;\r\n        if (l == r)return node->line(x);\r\
    \n        T m = (l + r) / 2;\r\n        if (m == r)m--;\r\n        if (x <= m)return\
    \ std::min(node->line(x), query(node->l, l, m, x));\r\n        else return std::min(node->line(x),\
    \ query(node->r, m + 1, r, x));\r\n    }\r\n\r\n    void add_line(T a, T b) {\r\
    \n        root = add_line(root, Line(a, b), x_min, x_max);\r\n    }\r\n\r\n  \
    \  void add_segment(T l, T r, T a, T b) {\r\n        root = add_segment(root,\
    \ Line(a, b), l, r - 1, x_min, x_max);\r\n    }\r\n\r\n    T query(T x) {\r\n\
    \        return query(root, x_min, x_max, x);\r\n    }\r\n};\r\n#line 3 \"verify/data-structure/line_add_get_min.test.cpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\ntypedef long long ll;\r\n\
    \r\nconstexpr int INF = 2147483647;\r\nconstexpr long long int INF_LL = 9223372036854775807;\r\
    \nint main() {\r\n    LiChaoTree<ll, -INF, INF> LCT;\r\n    int N, Q;\r\n    cin\
    \ >> N >> Q;\r\n    for (int i = 0; i < N; i++) {\r\n        ll a, b;\r\n    \
    \    cin >> a >> b;\r\n        LCT.add_line(a, b);\r\n    }\r\n    for (int i\
    \ = 0; i < Q; i++) {\r\n        ll t;\r\n        cin >> t;\r\n        if (t ==\
    \ 0) {\r\n            ll a, b;\r\n            cin >> a >> b;\r\n            LCT.add_line(a,\
    \ b);\r\n        }\r\n        else {\r\n            ll p;\r\n            cin >>\
    \ p;\r\n            cout << LCT.query(p) << endl;\r\n        }\r\n    }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\
    #include \"data-structure/li_chao_tree.cpp\"\r\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\ntypedef long long ll;\r\n\r\nconstexpr int INF = 2147483647;\r\
    \nconstexpr long long int INF_LL = 9223372036854775807;\r\nint main() {\r\n  \
    \  LiChaoTree<ll, -INF, INF> LCT;\r\n    int N, Q;\r\n    cin >> N >> Q;\r\n \
    \   for (int i = 0; i < N; i++) {\r\n        ll a, b;\r\n        cin >> a >> b;\r\
    \n        LCT.add_line(a, b);\r\n    }\r\n    for (int i = 0; i < Q; i++) {\r\n\
    \        ll t;\r\n        cin >> t;\r\n        if (t == 0) {\r\n            ll\
    \ a, b;\r\n            cin >> a >> b;\r\n            LCT.add_line(a, b);\r\n \
    \       }\r\n        else {\r\n            ll p;\r\n            cin >> p;\r\n\
    \            cout << LCT.query(p) << endl;\r\n        }\r\n    }\r\n}"
  dependsOn:
  - data-structure/li_chao_tree.cpp
  isVerificationFile: true
  path: verify/data-structure/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2021-03-03 22:23:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data-structure/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/verify/data-structure/line_add_get_min.test.cpp
- /verify/verify/data-structure/line_add_get_min.test.cpp.html
title: verify/data-structure/line_add_get_min.test.cpp
---
