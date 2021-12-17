#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int p, a[N];
std::vector<int> g[N];

// Segment Tree
void build(int, int, int);

// Heavy Path Decomposition
int cnt, id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_path(int, int, int);
void modify_tree(int, int);
long long query_path(int, int);
long long query_tree(int);

int main() {
    int n, m, r;
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(r, r);
    dfs2(r, r);
    build(1, 1, n);
    while (m--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            modify_path(x, y, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << query_path(x, y) << endl;
        } else if (op == 3) {
            cin >> x >> z;
            modify_tree(x, z);
        } else {
            cin >> x;
            cout << query_tree(x) << endl;
        }
    }
    return 0;
}

// === Segment Tree ===

struct node {
    int l, r;
    long long s, d;

    node()
        : l(0), r(0), s(0), d(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 2];

inline void pushup(int u) {
    tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s) % p;
}

inline void pushdown(int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.s = (left.s + (left.r - left.l + 1) * root.d) % p;
    left.d = (left.d + root.d) % p;
    right.s = (right.s + (right.r - right.l + 1) * root.d) % p;
    right.d = (right.d + root.d) % p;
    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[rid[l]] % p;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s = (tr[u].s + (tr[u].r - tr[u].l + 1) * d) % p;
        tr[u].d = (tr[u].d + d) % p;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s % p;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    long long res = 0;
    if (l <= mid) res = (res + query(u << 1, l, r)) % p;
    if (r > mid) res = (res + query(u << 1 | 1, l, r)) % p;
    return res;
}

// == Heavy Path Decomposition ===

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
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
    rid[id[u]] = u;
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

long long query_path(int u, int v) {
    long long sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        sum = (sum + query(1, id[top[u]], id[u])) % p;
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) std::swap(u, v);
    sum = (sum + query(1, id[v], id[u])) % p;
    return sum;
}

inline void modify_tree(int u, int d) {
    modify(1, id[u], id[u] + siz[u] - 1, d);
}

inline long long query_tree(int u) {
    return query(1, id[u], id[u] + siz[u] - 1);
}
