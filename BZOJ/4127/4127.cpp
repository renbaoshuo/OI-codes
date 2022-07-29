#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, a[N];
std::vector<int> g[N];
int cnt, id[N], rid[N], fa[N], dep[N], top[N], son[N], siz[N];

struct node {
    int l, r;
    long long sum, max, d;
    size_t size;

    node()
        : l(0),
          r(0),
          sum(0),
          max(std::numeric_limits<long long>::min()),
          d(0),
          size(0) {}

    node(int _l, int _r)
        : l(_l),
          r(_r),
          sum(0),
          max(std::numeric_limits<long long>::min()),
          d(0),
          size(0) {}
} tr1[N << 2], tr2[N << 2];  // tr1: 正数  tr2: 负数

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
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

inline void pushup(node* tr, int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].size = tr[u << 1].size + tr[u << 1 | 1].size;
}

inline void pushdown(node* tr, int u) {
    if (tr[u].d) {
        tr[u << 1].sum += tr[u].d * tr[u << 1].size;
        if (tr[u << 1].size) tr[u << 1].max += tr[u].d;
        tr[u << 1].d += tr[u].d;

        tr[u << 1 | 1].sum += tr[u].d * tr[u << 1 | 1].size;
        if (tr[u << 1 | 1].size) tr[u << 1 | 1].max += tr[u].d;
        tr[u << 1 | 1].d += tr[u].d;

        tr[u].d = 0;
    }
}

void build(int u, int l, int r) {
    tr1[u] = node(l, r);
    tr2[u] = node(l, r);

    if (l == r) {
        if (a[rid[l]] >= 0) {
            tr1[u].sum = a[rid[l]];
            tr1[u].max = a[rid[l]];
            tr1[u].size = 1;

        } else {
            tr2[u].sum = a[rid[l]];
            tr2[u].max = a[rid[l]];
            tr2[u].size = 1;
        }

        return;
    }

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(tr1, u);
    pushup(tr2, u);
}

long long query_sum(int u, int l, int r) {
    if (l <= tr1[u].l && tr1[u].r <= r) {
        return tr1[u].sum - tr2[u].sum;
    }

    int mid = tr1[u].l + tr1[u].r >> 1;
    long long res = 0;

    pushdown(tr1, u);
    pushdown(tr2, u);

    if (l <= mid) res += query_sum(u << 1, l, r);
    if (r > mid) res += query_sum(u << 1 | 1, l, r);

    return res;
}

long long query_max(node* tr, int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].max;
    }

    int mid = tr[u].l + tr[u].r >> 1;
    long long res = std::numeric_limits<long long>::min();

    pushdown(tr1, u);
    pushdown(tr2, u);

    if (l <= mid) res = std::max(res, query_max(tr, u << 1, l, r));
    if (r > mid) res = std::max(res, query_max(tr, u << 1 | 1, l, r));

    return res;
}

void swap_max(int u, int l, int r) {
    if (tr2[u].max <= 0) return;

    if (tr2[u].l == tr2[u].r) {
        tr1[u] = tr2[u];
        tr2[u] = node(l, r);

        return;
    }

    int mid = tr1[u].l + tr1[u].r >> 1;

    pushdown(tr1, u);
    pushdown(tr2, u);

    if (l <= mid) swap_max(u << 1, l, r);
    if (r > mid) swap_max(u << 1 | 1, l, r);

    pushup(tr1, u);
    pushup(tr2, u);
}

void modify(int u, int l, int r, int d) {
    if (l <= tr1[u].l && tr1[u].r <= r) {
        tr1[u].sum += d * tr1[u].size;
        tr1[u].d += d;
        if (tr1[u].size) tr1[u].max += d;

        tr2[u].sum += d * tr2[u].size;
        tr2[u].d += d;
        if (tr2[u].size) tr2[u].max += d;

        return;
    }

    int mid = tr1[u].l + tr1[u].r >> 1;

    pushdown(tr1, u);
    pushdown(tr2, u);

    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);

    pushup(tr1, u);
    pushup(tr2, u);
}

void modify_path(int u, int v, int d) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        modify(1, id[top[u]], id[u], d);
        swap_max(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);
    modify(1, id[v], id[u], d);
    swap_max(1, id[v], id[u]);
}

long long query_path(int u, int v) {
    long long res = 0;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        res += query_sum(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);
    res += query_sum(1, id[v], id[u]);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    build(1, 1, n);

    while (m--) {
        int op, u, v;

        cin >> op >> u >> v;

        if (op == 1) {
            int d;

            cin >> d;

            modify_path(u, v, d);
        } else {  // op == 2
            cout << query_path(u, v) << endl;
        }
    }

    return 0;
}
