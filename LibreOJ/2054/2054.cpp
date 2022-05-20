#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, q, u, v;
char op;
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, id[N], rid[N], fa[N], dep[N], son[N], siz[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_path(int);
int query_path(int);

// Segment Tree
void pushup(int);
void build(int, int, int);
void modify(int, int, int);
int query(int, int, int);

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    modify_path(1);
    while (q--) {
        cin >> op >> u;
        if (op == 'C') {
            modify_path(u);
        } else {
            cout << query_path(u) << endl;
        }
    }
    return 0;
}

// === Heavy Path Decomposition ===

void dfs1(int u, int f) {
    fa[u] = f;
    siz[u] = 1;
    dep[u] = dep[f] + 1;
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

inline void modify_path(int u) {
    modify(1, id[u], u);
}

int query_path(int u) {
    while (top[u] != 1) {
        int t = query(1, id[top[u]], id[u]);
        if (t != -1) return t;
        u = fa[top[u]];
    }
    int t = query(1, 1, id[u]);
    if (t == -1) return 1;
    return t;
}

// === Segment Tree ===

struct node {
    int l, r, d;

    node()
        : l(0), r(0), d(-1) {}

    node(int _l, int _r)
        : l(_l), r(_r), d(-1) {}
} tr[N << 2];

inline void pushup(int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (left.d != -1 && right.d != -1) {
        if (dep[left.d] > dep[right.d]) {
            root.d = left.d;
        } else {
            root.d = right.d;
        }
    } else if (left.d != -1) {
        root.d = left.d;
    } else if (right.d != -1) {
        root.d = right.d;
    } else {
        root.d = -1;
    }
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int x, int k) {
    if (tr[u].l == tr[u].r) {
        tr[u].d = k;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        modify(u << 1, x, k);
    } else {
        modify(u << 1 | 1, x, k);
    }
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].d;
    int mid = tr[u].l + tr[u].r >> 1;
    int left = -1, right = -1;
    if (l <= mid) left = query(u << 1, l, r);
    if (r > mid) right = query(u << 1 | 1, l, r);
    if (left != -1 && right != -1) {
        if (dep[left] > dep[right]) return left;
        return right;
    }
    if (left != -1) return left;
    if (right != -1) return right;
    return -1;
}
