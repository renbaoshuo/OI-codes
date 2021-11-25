#include <bits/stdc++.h>

using namespace std;

int n, m, r, p, a[100005], x, y, op, u, v, k;
vector<int> g[100005];
int cnt, dep[100005], fa[100005], siz[100005], son[100005], id[100005], top[100005], w[100005];

struct node {
    int l, r;
    long long s, d;

    node()
        : l(0), r(0), s(0), d(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[100005 << 2];

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
    w[cnt] = a[u];
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;
        dfs2(v, v);
    }
}

void pushup(int u) {
    tr[u].s = (tr[u << 1].s + tr[u << 1 | 1].s) % p;
}

void pushdown(int u) {
    if (!tr[u].d) return;
    tr[u << 1].s = (tr[u << 1].s + (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d) % p;
    tr[u << 1].d = (tr[u << 1].d + tr[u].d) % p;
    tr[u << 1 | 1].s = (tr[u << 1 | 1].s + (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d) % p;
    tr[u << 1 | 1].d = (tr[u << 1 | 1].d + tr[u].d) % p;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = w[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int k) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s = (tr[u].s + (tr[u].r - tr[u].l + 1) * k) % p;
        tr[u].d = (tr[u].d + k) % p;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, k);
    if (r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s % p;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long sum = 0;
    pushdown(u);
    if (l <= mid) sum = (sum + query(u << 1, l, r)) % p;
    if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
    return sum;
}

void modify_path(int u, int v, int k) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        modify(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    modify(1, id[v], id[u], k);
}

long long query_path(int u, int v) {
    long long sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        sum = (sum + query(1, id[top[u]], id[u])) % p;
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    sum = (sum + query(1, id[v], id[u])) % p;
    return sum;
}

void modify_tree(int u, int k) {
    modify(1, id[u], id[u] + siz[u] - 1, k);
}

long long query_tree(int u) {
    return query(1, id[u], id[u] + siz[u] - 1);
}

int main() {
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        cin >> op >> u;
        if (op == 1) {
            cin >> v >> k;
            modify_path(u, v, k);
        } else if (op == 2) {
            cin >> v;
            cout << query_path(u, v) % p << endl;
        } else if (op == 3) {
            cin >> k;
            modify_tree(u, k);
        } else {
            cout << query_tree(u) % p << endl;
        }
    }
    return 0;
}
