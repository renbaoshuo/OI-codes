#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

const int N = 5e4 + 5;
const int mod = 201314;

using std::cin;
using std::cout;
const char endl = '\n';

int n, q, now, ans[N];
int cnt, id[N], fa[N], dep[N], siz[N], top[N], son[N];
std::vector<int> g[N];
std::vector<std::tuple<int, int, int, int>> qs;

struct node {
    int l, r, s, d;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (!tr[u].d) return;

    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1].d += tr[u].d;

    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;

    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s += (tr[u].r - tr[u].l + 1) * x;
        tr[u].d += x;

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);

    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;

    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);

    return res;
}

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

    if (son[u]) dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void modify_path(int u, int v, int x) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        modify(1, id[top[u]], id[u], x);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);

    modify(1, id[v], id[u], x);
}

int query_path(int u, int v) {
    int res = 0;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);

    res += query(1, id[v], id[u]);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 2, x; i <= n; i++) {
        cin >> x;

        x++;
        g[i].emplace_back(x);
        g[x].emplace_back(i);
    }

    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    for (int i = 1, l, r, z; i <= q; i++) {
        cin >> l >> r >> z;

        l++, r++, z++;

        qs.emplace_back(i, l - 1, z, -1);
        qs.emplace_back(i, r, z, 1);
    }

    std::sort(qs.begin(), qs.end(), [&](const decltype(qs)::value_type &lhs, const decltype(qs)::value_type &rhs) -> bool {
        return std::get<1>(lhs) < std::get<1>(rhs);
    });

    for (auto o : qs) {
        int id, pos, z, k;

        std::tie(id, pos, z, k) = o;

        while (now < pos) modify_path(1, ++now, 1);

        ans[id] = ((ans[id] + k * query_path(1, z)) % mod + mod) % mod;
    }

    std::copy_n(ans + 1, q, std::ostream_iterator<int>(cout, "\n"));

    return 0;
}
