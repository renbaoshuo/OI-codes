#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, fa[N], ans[N];
std::tuple<int, int, int, int> edges[N];
std::vector<int> g[N];
std::vector<std::tuple<int, int, int>> qs;
int dep[N], siz[N], son[N], top[N];
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>>
    q[N];

class LinkCutTree {
  private:
    struct node {
        size_t lchild, rchild, father;
        int val, max;
        bool reversed;

        node()
            : lchild(0),
              rchild(0),
              father(0),
              val(0),
              max(0),
              reversed(false) {}

        size_t& child(const unsigned& x) {
            return !x ? lchild : rchild;
        }
    } tr[N << 1];

    void pushup(const size_t& u) {
        tr[u].max = std::max({tr[u].val, tr[tr[u].lchild].max, tr[tr[u].rchild].max});
    }

    void pushdown(const size_t& u) {
        if (!tr[u].reversed) return;
        std::swap(tr[u].lchild, tr[u].rchild);
        tr[tr[u].lchild].reversed = !tr[tr[u].lchild].reversed;
        tr[tr[u].rchild].reversed = !tr[tr[u].rchild].reversed;
        tr[u].reversed = false;
    }

    bool relation(const size_t& u) {
        return u == tr[tr[u].father].lchild ? 0 : 1;
    }

    bool is_root(const size_t& u) {
        return tr[tr[u].father].lchild != u && tr[tr[u].father].rchild != u;
    }

    void rotate(const size_t& u) {
        size_t p = tr[u].father;
        bool x = relation(u);

        if (!is_root(p)) tr[tr[p].father].child(relation(p)) = u;
        tr[u].father = tr[p].father;

        if (tr[u].child(x ^ 1)) tr[tr[u].child(x ^ 1)].father = p;
        tr[p].child(x) = tr[u].child(x ^ 1);

        tr[u].child(x ^ 1) = p;
        tr[p].father = u;

        pushup(p);
        pushup(u);
    }

    void splay(size_t u) {
        std::stack<size_t> st;

        size_t cur = u;
        st.emplace(cur);

        while (!is_root(cur)) {
            st.emplace(tr[cur].father);
            cur = tr[cur].father;
        }

        while (!st.empty()) {
            pushdown(st.top());
            st.pop();
        }

        while (!is_root(u)) {
            if (is_root(tr[u].father)) {
                rotate(u);
            } else if (relation(u) == relation(tr[u].father)) {
                rotate(tr[u].father);
                rotate(u);
            } else {
                rotate(u);
                rotate(u);
            }
        }
    }

    void access(size_t u) {
        for (size_t f = 0; u; u = tr[f = u].father) {
            splay(u);
            tr[u].rchild = f;
            pushup(u);
        }
    }

    void make_root(const size_t& u) {
        access(u);
        splay(u);
        tr[u].reversed = !tr[u].reversed;
    }

    size_t find_root(size_t u) {
        access(u);
        splay(u);

        while (tr[u].lchild) {
            u = tr[u].lchild;
        }

        return u;
    }

    void split(const size_t& x, const size_t& y) {
        make_root(x);
        access(y);
        splay(y);
    }

  public:
    bool check(const int& x, const int& y) {
        return find_root(x) == find_root(y);
    }

    int query(const int& x, const int& y) {
        split(x, y);

        return tr[y].max;
    }

    void link(const int& x, const int& y) {
        make_root(x);

        if (find_root(y) != x) {
            tr[x].father = y;
        }
    }

    void cut(const int& x, const int& y) {
        split(x, y);

        if (tr[y].lchild == x) {
            tr[y].lchild = tr[x].father = 0;
        }
    }

    void set(const int& x, const int& y) {
        tr[x].max = tr[x].val = y;
    }
} lct;

int find(const int& x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    fa[u] = f;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);

        siz[u] += siz[v];

        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;

        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

void dfs3(int u) {
    for (int v : g[u]) {
        if (v == fa[u]) continue;

        dfs3(v);

        if (q[v].size() > q[u].size()) std::swap(q[u], q[v]);

        while (!q[v].empty()) {
            if (dep[q[v].top().second] <= dep[u]) q[u].emplace(q[v].top());
            q[v].pop();
        }
    }

    while (!q[u].empty() && dep[q[u].top().second] > dep[u]) q[u].pop();
    if (u > n && !q[u].empty()) ans[u - n] = q[u].top().first;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::iota(fa, fa + N, 0);
    std::fill(std::begin(ans), std::end(ans), -1);

    cin >> n >> m;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        edges[i] = {u, v, w, i};
    }

    std::sort(edges + 1, edges + 1 + m, [&](const std::tuple<int, int, int, int>& a, const std::tuple<int, int, int, int>& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    for (int i = 1; i <= m; i++) {
        int u, v, w, id;

        std::tie(u, v, w, id) = edges[i];

        int x = find(u),
            y = find(v);

        lct.set(id + n, w);

        if (x != y) {
            fa[x] = y;
            lct.link(u, id + n);
            lct.link(id + n, v);
            g[u].emplace_back(id + n);
            g[v].emplace_back(id + n);
            g[id + n].emplace_back(u);
            g[id + n].emplace_back(v);
        } else {
            ans[id] = lct.query(v, u) - 1;
            qs.emplace_back(u, v, w - 1);
        }
    }

    std::fill(std::begin(fa), std::end(fa), 0);
    dfs1(1, 0);
    dfs2(1, 1);

    for (auto o : qs) {
        int u, v, w;

        std::tie(u, v, w) = o;

        int x = lca(u, v);

        if (u != x) q[u].emplace(w, x);
        if (v != x) q[v].emplace(w, x);
    }

    dfs3(1);

    std::copy_n(ans + 1, m, std::ostream_iterator<int>(cout, " "));

    cout << endl;

    return 0;
}
