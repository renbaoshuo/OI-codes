#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 1e5 + 5;

int n, m, l, r, root, cnt;

struct node {
    int l, r, s, v, k;
    bool d;

    node()
        : l(0),
          r(0),
          s(0),
          v(0),
          d(false),
          k(rand()) {}

    node(int _v)
        : l(0),
          r(0),
          s(1),
          v(_v),
          d(false),
          k(rand()) {}
} tr[N];

void pushup(int u) {
    tr[u].s = tr[tr[u].l].s + tr[tr[u].r].s + 1;
}

void pushdown(int u) {
    if (tr[u].d) {
        tr[u].d = false;
        tr[tr[u].l].d ^= 1;
        tr[tr[u].r].d ^= 1;
        std::swap(tr[u].l, tr[u].r);
    }
}

int build(int l, int r) {
    if (l > r) return 0;
    int mid = l + r >> 1;
    int p = ++cnt;
    tr[p] = node(mid - 1);
    tr[p].l = build(l, mid - 1);
    tr[p].r = build(mid + 1, r);
    pushup(p);
    return p;
}

std::pair<int, int> split(int p, int k) {
    if (!p) return std::make_pair(0, 0);
    pushdown(p);
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

int merge(int x, int y) {
    if (!x || !y) return x | y;
    pushdown(x);
    pushdown(y);
    if (tr[x].k > tr[y].k) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    }
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
}

void reserve(int l, int r) {
    auto x = split(root, r + 1);
    auto y = split(x.first, l);
    tr[y.second].d ^= 1;
    root = merge(merge(y.first, y.second), x.second);
}

void print(int p) {
    if (!p) return;
    pushdown(p);
    print(tr[p].l);
    if (1 <= tr[p].v && tr[p].v <= n) {
        cout << tr[p].v << ' ';
    }
    print(tr[p].r);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    root = build(1, n + 2);
    while (m--) {
        cin >> l >> r;
        reserve(l, r);
    }
    print(root);
    cout << endl;
    return 0;
}
