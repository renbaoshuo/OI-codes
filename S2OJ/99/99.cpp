#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 100005;

// Treap
void insert(int);
void erase(int);
int getRank(int);
int getKth(int);

int n, op, x;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            insert(x);
        } else if (op == 2) {
            erase(x);
        } else if (op == 3) {
            cout << getRank(x) << endl;
        } else if (op == 4) {
            cout << getKth(x) << endl;
        } else if (op == 5) {
            cout << getKth(getRank(x) - 1) << endl;
        } else {
            cout << getKth(getRank(x + 1)) << endl;
        }
    }
    return 0;
}

// === Treap ===

int root, cnt;

struct node {
    int l, r, s, v, k;

    node()
        : l(0), r(0), s(0), v(0), k(rand()) {}
    node(int _v)
        : l(0), r(0), s(1), v(_v), k(rand()) {}
} tr[N];

inline void pushup(int u) {
    tr[u].s = tr[tr[u].l].s + tr[tr[u].r].s + 1;
}

std::pair<int, int> split(int p, int k) {
    if (!p) return std::make_pair(0, 0);
    if (k <= tr[tr[p].l].s) {
        auto o = split(tr[p].l, k);
        tr[p].l = o.second;
        pushup(p);
        o.second = p;
        return o;
    }
    auto o = split(tr[p].r, k - tr[tr[p].l].s - 1);
    tr[p].r = o.first;
    pushup(p);
    o.first = p;
    return o;
}

std::pair<int, int> splitByValue(int p, int v) {
    if (!p) return std::make_pair(0, 0);
    if (tr[p].v < v) {
        auto o = splitByValue(tr[p].r, v);
        tr[p].r = o.first;
        pushup(p);
        o.first = p;
        return o;
    }
    auto o = splitByValue(tr[p].l, v);
    tr[p].l = o.second;
    pushup(p);
    o.second = p;
    return o;
}

int merge(int x, int y) {
    if (!x) return y;
    if (!y) return x;
    if (tr[x].k > tr[y].k) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    }
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
}

int find(int p, int v) {
    if (!p) return 0;
    if (tr[p].v == v) return p;
    if (tr[p].v > v) return find(tr[p].l, v);
    return find(tr[p].r, v);
}

void insert(int v) {
    auto o = splitByValue(root, v);
    int p = ++cnt;
    tr[p] = node(v);
    o.first = merge(o.first, p);
    root = merge(o.first, o.second);
}

void erase(int v) {
    auto o = splitByValue(root, v);
    auto t = o;
    if (find(o.second, v)) {
        t = split(o.second, 1);
    }
    root = merge(o.first, t.second);
}

int _getRank(int p, int v) {
    if (!p) return 1;
    if (v <= tr[p].v) return _getRank(tr[p].l, v);
    return tr[tr[p].l].s + 1 + _getRank(tr[p].r, v);
}

inline int getRank(int v) {
    return _getRank(root, v);
}

int getKth(int k) {
    auto x = split(root, k - 1);
    auto y = split(x.second, 1);
    int o = y.first;
    root = merge(x.first, merge(y.first, y.second));
    return tr[o].v;
}
