#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1.5e5 + 5;

int n, m, q, cnt, qr[N], lst[N];
long long res, w[N];
std::tuple<int, int, long long> edges[N];
std::vector<long long> ans;

class LinkCutTree {
  private:
    struct node {
        size_t l, r, f;
        int m;
        bool rev;

        node(const int &_p = 0, const size_t &_f = 0)
            : l(0), r(0), f(_f), m(_p), rev(false) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N];

    inline void pushup(size_t u) {
        tr[u].m = u;

        if (tr[u].l && w[tr[tr[u].l].m] > w[tr[u].m])
            tr[u].m = tr[tr[u].l].m;

        if (tr[u].r && w[tr[tr[u].r].m] > w[tr[u].m])
            tr[u].m = tr[tr[u].r].m;
    }

    inline void pushdown(const size_t &u) {
        if (!tr[u].rev) return;

        std::swap(tr[u].l, tr[u].r);
        tr[tr[u].l].rev = !tr[tr[u].l].rev;
        tr[tr[u].r].rev = !tr[tr[u].r].rev;
        tr[u].rev = false;
    }

    unsigned relation(const size_t &u) {
        return u == tr[tr[u].f].l ? 0 : 1;
    }

    bool isRoot(const size_t &u) {
        return tr[tr[u].f].l != u && tr[tr[u].f].r != u;
    }

    void rotate(size_t u) {
        size_t p = tr[u].f;
        unsigned x = relation(u);

        if (!isRoot(p)) {
            tr[tr[p].f].child(relation(p)) = u;
        }
        tr[u].f = tr[p].f;

        if (tr[u].child(x ^ 1)) {
            tr[tr[u].child(x ^ 1)].f = p;
        }
        tr[p].child(x) = tr[u].child(x ^ 1);

        tr[u].child(x ^ 1) = p;
        tr[p].f = u;

        pushup(p);
        pushup(u);
    }

    void splay(size_t u) {
        std::stack<size_t> st;

        size_t cur = u;
        st.push(cur);
        while (!isRoot(cur)) {
            st.push(tr[cur].f);
            cur = tr[cur].f;
        }

        while (!st.empty()) {
            pushdown(st.top());
            st.pop();
        }

        while (!isRoot(u)) {
            if (isRoot(tr[u].f)) {
                rotate(u);
            } else if (relation(u) == relation(tr[u].f)) {
                rotate(tr[u].f);
                rotate(u);
            } else {
                rotate(u);
                rotate(u);
            }
        }
    }

    void access(size_t u) {
        for (size_t f = 0; u; u = tr[f = u].f) {
            splay(u);
            tr[u].r = f;
            pushup(u);
        }
    }

    void makeRoot(const size_t &u) {
        access(u);
        splay(u);
        tr[u].rev = !tr[u].rev;
    }

    size_t findRoot(size_t u) {
        access(u);
        splay(u);

        while (tr[u].l) {
            u = tr[u].l;
        }

        return u;
    }

    void split(const size_t &x, const size_t &y) {
        makeRoot(x);
        access(y);
        splay(y);
    }

  public:
    bool check(int x, int y) {
        return findRoot(x) == findRoot(y);
    }

    void set(int p, int v) {
        tr[p].m = v;
    }

    unsigned query(int x, int y) {
        split(x, y);

        return tr[y].m;
    }

    void link(const int &x, const int &y) {
        makeRoot(x);

        if (findRoot(y) != x) {
            tr[x].f = y;
        }
    }

    void cut(int x, int y) {
        split(x, y);

        if (tr[y].l == x) {
            tr[y].l = 0;
            tr[x].f = 0;
        }
    }
} lct;

struct node {
    int l, r;
    std::vector<int> vec;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void insert(int u, int l, int r, int id) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].vec.emplace_back(id);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) insert(u << 1, l, r, id);
    if (r > mid) insert(u << 1 | 1, l, r, id);
}

void solve(int u) {
    std::stack<std::pair<int, bool>> st;

    for (int id : tr[u].vec) {
        int x, y;
        long long w;

        std::tie(x, y, w) = edges[id];

        if (lct.check(x, y)) {
            int id2 = lct.query(x, y) - n,
                x2, y2;
            long long w2;

            std::tie(x2, y2, w2) = edges[id2];

            if (w2 <= w) continue;

            lct.cut(x2, id2 + n);
            lct.cut(id2 + n, y2);
            st.emplace(id2, true);
            res -= w2;
        }

        lct.link(x, id + n);
        lct.link(id + n, y);
        st.emplace(id, false);
        res += w;
    }

    if (tr[u].l == tr[u].r) {
        ans.emplace_back(res);
    } else {
        solve(u << 1);
        solve(u << 1 | 1);
    }

    while (!st.empty()) {
        int id;
        bool type;

        std::tie(id, type) = st.top();
        st.pop();

        int x, y;
        long long w;

        std::tie(x, y, w) = edges[id];

        if (type) {
            lct.link(x, id + n);
            lct.link(id + n, y);
            res += w;
        } else {
            lct.cut(x, id + n);
            lct.cut(id + n, y);
            res -= w;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;

        cin >> x >> y >> z;

        w[n + (++cnt)] = z;
        edges[cnt] = {x, y, z};
        lst[i] = q + 1;
    }

    for (int i = 1; i <= q; i++) {
        int k;
        long long d;

        cin >> k >> d;

        qr[i] = k;
        w[n + (++cnt)] = d;
        edges[cnt] = {std::get<0>(edges[k]), std::get<1>(edges[k]), d};
    }

    build(1, 1, q);

    for (int i = q; i; i--) {
        insert(1, i, lst[qr[i]] - 1, m + i);
        lst[qr[i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        if (lst[i] > 1) {
            insert(1, 1, lst[i] - 1, i);
        }
    }

    solve(1);

    for (auto x : ans) cout << x << endl;

    return 0;
}
