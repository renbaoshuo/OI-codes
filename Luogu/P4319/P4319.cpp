#include <iostream>
#include <iterator>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;
const int LIMIT = 32766;

int n, m, cnt, w[N];
long long res;
std::tuple<int, int, int> edges[N];
std::vector<long long> ans;

class LinkCutTree {
  private:
    struct node {
        size_t lchild, rchild, father;
        int max_id;
        bool reversed;

        node()
            : lchild(0),
              rchild(0),
              father(0),
              max_id(0),
              reversed(false) {}

        size_t& child(const unsigned& x) {
            return !x ? lchild : rchild;
        }
    } tr[N];

    void pushup(const size_t& u) {
        tr[u].max_id = u;

        if (tr[u].lchild && w[tr[tr[u].lchild].max_id] > w[tr[u].max_id]) {
            tr[u].max_id = tr[tr[u].lchild].max_id;
        }

        if (tr[u].rchild && w[tr[tr[u].rchild].max_id] > w[tr[u].max_id]) {
            tr[u].max_id = tr[tr[u].rchild].max_id;
        }
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

        return tr[y].max_id;
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

struct node : std::vector<int> {
    int l, r;
} tr[N];

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;

    if (l == r) return;

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void insert(int u, int l, int r, int id) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].emplace_back(id);
        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;

    if (l <= mid) insert(u << 1, l, r, id);
    if (r > mid) insert(u << 1 | 1, l, r, id);
}

void solve(int u) {
    std::stack<std::pair<int, bool>> st;

    for (int id : tr[u]) {
        int u, v, w;

        std::tie(u, v, w) = edges[id];

        if (lct.check(u, v)) {
            int id2 = lct.query(u, v) - n,
                u2, v2, w2;

            std::tie(u2, v2, w2) = edges[id2];

            if (w2 <= w) continue;

            lct.cut(u2, id2 + n);
            lct.cut(id2 + n, v2);
            st.emplace(id2, true);
            res -= w2;
        }

        lct.link(u, id + n);
        lct.link(id + n, v);
        st.emplace(id, false);
        res += w;
    }

    if (tr[u].l == tr[u].r) {
        ans.emplace_back(res + 1);
    } else {
        solve(u << 1);
        solve(u << 1 | 1);
    }

    while (!st.empty()) {
        int id, u, v, w;
        bool type;

        std::tie(id, type) = st.top();
        std::tie(u, v, w) = edges[id];
        st.pop();

        if (type) {
            lct.link(u, id + n);
            lct.link(id + n, v);
            res += w;
        } else {
            lct.cut(u, id + n);
            lct.cut(id + n, v);
            res -= w;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    build(1, 1, LIMIT);

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        edges[++cnt] = {u, v, w};
        ::w[n + cnt] = w;
        insert(1, 1, LIMIT, cnt);
    }

    cin >> m;

    for (int i = 1, u, v, w, l, r; i <= m; i++) {
        cin >> u >> v >> w >> l >> r;

        edges[++cnt] = {u, v, w};
        ::w[n + cnt] = w;

        insert(1, l, r, cnt);
    }

    solve(1);

    std::copy(ans.begin(), ans.end(), std::ostream_iterator<decltype(ans)::value_type>(cout, "\n"));

    return 0;
}
