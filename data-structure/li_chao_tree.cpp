#pragma once
#include <limits>
#include <algorithm>
#include <utility>

template<class T, T x_min, T x_max, T inf = std::numeric_limits<T>::max()>
struct LiChaoTree {
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b) {}
        T operator() (T x) { return x * a + b; }
    };
    struct Node {
        Line line;
        Node* l, * r;
        Node(const Line& x) : line(x), l(nullptr), r(nullptr) {};
    };
    Node* root;
    LiChaoTree() : root(nullptr) { }

    Node* add_line(Node* node, Line line, T l, T r) {
        if (!node)return new Node(line);

        T m = (l + r) / 2;
        if (m == r)m--;
        T node_l = node->line(l), node_m = node->line(m), node_r = node->line(r);
        T line_l = line(l), line_m = line(m), line_r = line(r);

        if (node_l <= line_l && node_r <= line_r) return node;
        else if (node_l >= line_l && node_r >= line_r) {
            node->line = line;
            return node;
        }
        else {
            if (node_m > line_m) {
                std::swap(node->line, line);
                if (line_l >= node_l) node->l = add_line(node->l, line, l, m);
                else node->r = add_line(node->r, line, m + 1, r);
            }
            else {
                if (node_l >= line_l) node->l = add_line(node->l, line, l, m);
                else node->r = add_line(node->r, line, m + 1, r);
            }
            return node;
        }
    }

    Node* add_segment(Node* node, Line line, T a, T b, T l, T r) {
        if (r < a || b < l)return node;
        if (a <= l && r <= b)return add_line(node, line, l, r);
        if (node) {
            if (node->line(l) <= line(l) && node->line(r) <= line(r))return node;
        }
        else node = new Node(Line(0, inf));
        T m = (l + r) / 2;
        if (m == r)m--;
        node->l = add_segment(node->l, line, a, b, l, m);
        node->r = add_segment(node->r, line, a, b, m + 1, r);
        return node;
    }

    T query(Node* node, T l, T r, T x) {
        if (!node)return inf;
        if (l == r)return node->line(x);
        T m = (l + r) / 2;
        if (m == r)m--;
        if (x <= m)return std::min(node->line(x), query(node->l, l, m, x));
        else return std::min(node->line(x), query(node->r, m + 1, r, x));
    }

    void add_line(T a, T b) {
        root = add_line(root, Line(a, b), x_min, x_max);
    }

    void add_segment(T l, T r, T a, T b) {
        root = add_segment(root, Line(a, b), l, r - 1, x_min, x_max);
    }

    T query(T x) {
        return query(root, x_min, x_max, x);
    }
};
