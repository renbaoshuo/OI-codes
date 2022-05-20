#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, q, a, x;
std::string op;
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, id[N], fa[N], dep[N], son[N], siz[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_path(int, int, int);
void modify_tree(int, int);

// Segment Tree
void pushup(int);
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, int);
int query(int, int, int);

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        x++;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while (q--) {
        cin >> op >> x;
        x++;
        int before = query(1, 1, n);
        if (op == "install") {
            if (!query(1, id[x], id[x])) {
                modify_path(1, x, 1);
            }
        } else {
            if (query(1, id[x], id[x])) {
                modify_tree(x, 0);
            }
        }
        int after = query(1, 1, n);
        cout << std::abs(before - after) << endl;
    }
    return 0;
}

// === Heavy Path Decomposition ===

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
    siz[u] = 1;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    id[u] = ++cnt;
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

void modify_path(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u], d);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[v], id[u], d);
}

void modify_tree(int u, int d) {
    modify(1, id[u], id[u] + siz[u] - 1, d);
}

// === Segment Tree ===

struct node {
    int l, r, s, d;

    node()
        : l(0), r(0), s(0), d(-1) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(-1) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

inline void pushdown(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.d == -1) return;
    left.s = (left.r - left.l + 1) * root.d;
    left.d = root.d;
    right.s = (right.r - right.l + 1) * root.d;
    right.d = root.d;
    root.d = -1;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s = (tr[u].r - tr[u].l + 1) * d;
        tr[u].d = d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s;
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    pushdown(u);
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
