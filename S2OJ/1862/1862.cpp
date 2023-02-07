#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, k, c[N], cnt, ans = 0x3f3f3f3f;
int id[N], rid[N], fa[N], dep[N], siz[N], son[N], top[N];
std::vector<int> g[N], g2[N], pos[N];
int dfn[N], low[N], scc_cnt, scc_id[N];
int res_siz[N], deg[N];
std::stack<int> st;
bool vis[N];

struct node {
    int l, r;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l), r(_r) {}
} tr[N << 2];

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
    static int cnt = 0;

    rid[id[u] = ++cnt] = u;
    top[u] = t;

    if (son[u]) dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    cnt++;

    if (l == r) {
        g2[k + u].emplace_back(c[rid[l]]);

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    g2[k + u].emplace_back(k + (u << 1));
    g2[k + u].emplace_back(k + (u << 1 | 1));
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        g2[x].emplace_back(k + u);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);
}

void modify_path(int u, int v) {
    int x = c[u];

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        modify(1, id[top[u]], id[u], x);
        u = fa[top[u]];
    }

    if (dep[v] > dep[u]) std::swap(u, v);

    modify(1, id[v], id[u], x);
}

void tarjan(int u) {
    static int cnt = 0;

    dfn[u] = low[u] = ++cnt;
    st.emplace(u);
    vis[u] = true;

    for (int v : g2[u]) {
        if (!dfn[v]) {
            tarjan(v);

            low[u] = std::min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        scc_cnt++;

        int v;
        do {
            v = st.top();
            st.pop();
            scc_id[v] = scc_cnt;
            vis[v] = false;
        } while (v != u);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];

        pos[c[i]].emplace_back(i);
    }

    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    for (int i = 1; i <= k; i++) {
        if (pos[i].size() <= 1) continue;

        int p = pos[i][0];

        for (int j = 1; j < pos[i].size(); j++) {
            int l = lca(pos[i][0], pos[i][j]);

            if (l != pos[i][j]) modify_path(pos[i][j], l);
            if (dep[l] < dep[p]) p = l;
        }

        if (p != pos[i][0]) {
            modify_path(pos[i][0], p);
        }
    }

    for (int i = 1; i <= k + cnt; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= k; i++) {
        res_siz[scc_id[i]]++;
    }

    for (int i = 1; i <= k + cnt; i++) {
        for (int v : g2[i]) {
            if (scc_id[i] != scc_id[v]) {
                deg[scc_id[i]]++;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        if (deg[scc_id[i]] == 0) {
            ans = std::min(ans, res_siz[scc_id[i]] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
