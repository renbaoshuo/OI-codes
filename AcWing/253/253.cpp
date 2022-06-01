#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, op, x;

// Treap
void insert(int);
void erase(int);
int getRank(int);
int getKth(int);

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
        : l(0),
          r(0),
          s(0),
          v(0),
          k(rand()) {}

    node(int _v)
        : l(0),
          r(0),
          s(1),
          v(_v),
          k(rand()) {}
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
    if (!x || !y) return x | y;
    if (tr[x].k > tr[y].k) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    }
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
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
    auto t = split(o.second, 1);
    if (tr[t.first].v == v) {
        root = merge(o.first, t.second);
    } else {
        root = merge(o.first, merge(t.first, t.second));
    }
}

int getRank(int v) {
    auto o = splitByValue(root, v);
    int r = tr[o.first].s + 1;
    root = merge(o.first, o.second);
    return r;
}

int getKth(int k) {
    auto x = split(root, k - 1);
    auto y = split(x.second, 1);
    int r = y.first;
    root = merge(x.first, merge(y.first, y.second));
    return tr[r].v;
}
