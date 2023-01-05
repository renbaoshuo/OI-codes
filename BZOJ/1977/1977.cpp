#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 3e5 + 5;

int n, m, a[N + M];
long long res, ans = std::numeric_limits<long long>::max();
std::tuple<int, int, int> edges[M];
bool vis[M];

class LinkCutTree {
  private:
    struct node {
        size_t lchild, rchild, father;
        int max1, max2;
        bool reversed;

        node()
            : lchild(0),
              rchild(0),
              father(0),
              max1(0),
              max2(0),
              reversed(false) {}

        size_t& child(const unsigned& x) {
            return !x ? lchild : rchild;
        }
    } tr[N + M];

    void pushup(const size_t& u) {
        tr[u].max1 = a[u];

        if (tr[u].max1 < tr[tr[u].lchild].max1) {
            tr[u].max2 = tr[u].max1;
            tr[u].max1 = tr[tr[u].lchild].max1;
        } else if (tr[u].max1 > tr[tr[u].lchild].max1) {
            tr[u].max2 = std::max(tr[u].max2, tr[tr[u].lchild].max1);
        }

        if (tr[u].max1 < tr[tr[u].rchild].max1) {
            tr[u].max2 = tr[u].max1;
            tr[u].max1 = tr[tr[u].rchild].max1;
        } else if (tr[u].max1 > tr[tr[u].rchild].max1) {
            tr[u].max2 = std::max(tr[u].max2, tr[tr[u].rchild].max1);
        }

        tr[u].max2 = std::max({tr[u].max2, tr[tr[u].lchild].max2, tr[tr[u].rchild].max2});
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

    std::pair<int, int> query(const int& x, const int& y) {
        split(x, y);

        return {tr[y].max1, tr[y].max2};
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

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;

        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }

    std::sort(edges + 1, edges + m + 1, [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    DSU dsu(n);

    for (int i = 1; i <= m; i++) {
        int u = std::get<0>(edges[i]),
            v = std::get<1>(edges[i]),
            x = dsu.find(u),
            y = dsu.find(v),
            w = std::get<2>(edges[i]);

        a[n + i] = w;

        if (x != y) {
            dsu.merge(x, y);
            lct.link(u, i + n);
            lct.link(i + n, v);
            res += w;
            vis[i] = true;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (vis[i]) continue;

        int u, v, w;

        std::tie(u, v, w) = edges[i];
        auto max = lct.query(u, v);

        if (w > max.first) {
            ans = std::min(ans, static_cast<long long>(w) - max.first);
        } else {
            ans = std::min(ans, static_cast<long long>(w) - max.second);
        }
    }

    cout << res + ans << endl;

    return 0;
}
