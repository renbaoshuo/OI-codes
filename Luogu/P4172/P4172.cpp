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

const int N = 1005,
          M = 2e5 + 5;

int n, m, q, id[N][N], a[M];
std::tuple<int, int, int, bool> edges[M];
std::tuple<int, int, int> qs[M];

class LinkCutTree {
  private:
    struct node {
        size_t lchild, rchild, father;
        int val, max;
        bool reversed;

        size_t& child(const bool& x) {
            return !x ? lchild : rchild;
        }
    } tr[M];

    void pushup(const size_t& u) {
        tr[u].max = std::max({tr[u].val, tr[tr[u].lchild].max, tr[tr[u].rchild].max});
    }

    void pushdown(const size_t& u) {
        if (!tr[u].reversed) return;

        std::swap(tr[u].lchild, tr[u].rchild);
        tr[tr[u].lchild].reversed ^= 1;
        tr[tr[u].rchild].reversed ^= 1;
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
        tr[u].reversed ^= 1;
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
    void set(int p, int v) {
        tr[p].max = tr[p].val = v;
    }

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

    int find(const int& u, const int& x) {
        if (a[u] == x) return u;
        if (tr[tr[u].lchild].max == x) return find(tr[u].lchild, x);
        return find(tr[u].rchild, x);
    }
} lct;

struct DSU : private std::vector<int> {
    DSU(const int& _n)
        : std::vector<int>(_n + 1) {
        std::iota(begin(), end(), 0);
    }

    int find(const int& x) {
        return x == at(x) ? x : at(x) = find(at(x));
    }

    bool check(const int& x, const int& y) {
        return find(x) == find(y);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) at(x) = y;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;

        edges[i] = {u, v, w, true};
    }

    std::sort(edges + 1, edges + 1 + m, [&](std::tuple<int, int, int, bool> a, std::tuple<int, int, int, bool> b) { return std::get<2>(a) < std::get<2>(b); });

    for (int i = 1, u, v, w; i <= m; i++) {
        std::tie(u, v, w, std::ignore) = edges[i];

        a[n + i] = w;
        lct.set(n + i, w);
        id[u][v] = id[v][u] = i;
    }

    for (int i = 1, k, u, v; i <= q; i++) {
        cin >> k >> u >> v;

        qs[i] = {k, u, v};

        if (k == 2) std::get<3>(edges[id[u][v]]) = false;
    }

    DSU dsu(n);
    std::vector<int> ans;

    for (int i = 1; i <= m; i++) {
        int u, v;
        bool available;

        std::tie(u, v, std::ignore, available) = edges[i];

        if (available && !dsu.check(u, v)) {
            dsu.merge(u, v);
            lct.link(u, n + i);
            lct.link(v, n + i);
        }
    }

    for (int i = q; i; i--) {
        int k, u, v;

        std::tie(k, u, v) = qs[i];

        int s = lct.query(u, v);

        if (k == 1) {
            ans.emplace_back(s);
        } else {
            int t = lct.find(v, s),
                u2, v2;

            std::tie(u2, v2, std::ignore, std::ignore) = edges[t - n];

            if (a[id[u][v] + n] < s) {
                lct.cut(u2, t);
                lct.cut(v2, t);
                lct.link(u, id[u][v] + n);
                lct.link(v, id[u][v] + n);
            }
        }
    }

    std::copy(ans.crbegin(), ans.crend(), std::ostream_iterator<decltype(ans)::value_type>(cout, "\n"));

    return 0;
}
