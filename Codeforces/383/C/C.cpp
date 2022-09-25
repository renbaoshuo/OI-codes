#include <cstdio>
#include <vector>

const int N = 200005;

int n, q, u, v, op, a[N];
std::vector<int> g[N];

// Heavy Path Decomposition
int cnt, id[N], rid[N], fa[N], dep[N], son[N], siz[N], top[N];
void dfs1(int, int);
void dfs2(int, int);
void modify_tree(int, int);
int query_point(int);

// Segment Tree
void pushdown(int);
void build(int, int, int);
void modify(int, int, int, int);
int query(int, int);

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    while (q--) {
        scanf("%d%d", &op, &u);
        if (op == 1) {
            scanf("%d", &v);
            modify_tree(u, v);
        } else {
            printf("%d\n", query_point(u));
        }
    }
    return 0;
}

// === Heavy Path Decomposition ===

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
    rid[cnt] = u;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

inline void modify_tree(int u, int d) {
    modify(1, id[u], id[u] + siz[u] - 1, d * ((dep[u] & 1) ? 1 : -1));
}

inline int query_point(int x) {
    return query(1, id[x]);
}

// === Segment Tree ===

struct node {
    int l, r, d;

    node()
        : l(0),
          r(0),
          d(0) {}

    node(int _l, int _r)
        : l(_l),
          r(_r),
          d(0) {}
} tr[N << 2];

void pushdown(int u) {
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (!root.d) return;
    if (left.l == left.r) {
        left.d += root.d * ((dep[rid[left.l]] & 1) ? 1 : -1);
    } else {
        left.d += root.d;
    }
    if (right.l == right.r) {
        right.d += root.d * ((dep[rid[right.l]] & 1) ? 1 : -1);
    } else {
        right.d += root.d;
    }
    root.d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].d = a[rid[l]];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        if (tr[u].l == tr[u].r) {
            tr[u].d += d * ((dep[rid[tr[u].l]] & 1) ? 1 : -1);
        } else {
            tr[u].d += d;
        }
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
}

int query(int u, int x) {
    if (tr[u].l == tr[u].r) return tr[u].d;
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (x <= mid) return query(u << 1, x);
    return query(u << 1 | 1, x);
}
