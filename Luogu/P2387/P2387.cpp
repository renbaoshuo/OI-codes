#include <iostream>
#include <algorithm>
#include <limits>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005,
          M = 1e5 + 5;

class LinkCutTree {
  private:
    struct node {
        size_t l, r, f;
        int v, m;
        unsigned id;
        bool rev;

        node()
            : l(0), r(0), f(0), v(0), m(std::numeric_limits<int>::min()), id(0), rev(false) {}

        node(int _v, size_t _f, unsigned _id)
            : l(0), r(0), f(_f), v(_v), m(_v), id(_id), rev(false) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N + M];

    inline void pushup(size_t u) {
        tr[u].m = tr[u].v;
        tr[u].id = u;

        if (tr[u].l && tr[u].m < tr[tr[u].l].m) {
            tr[u].m = tr[tr[u].l].m;
            tr[u].id = tr[tr[u].l].id;
        }

        if (tr[u].r && tr[u].m < tr[tr[u].r].m) {
            tr[u].m = tr[tr[u].r].m;
            tr[u].id = tr[tr[u].r].id;
        }
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

  public:
    void set(int p, int v) {
        tr[p].m = tr[p].v = v;
    }

    int query(int x, int y) {
        split(x, y);

        return tr[y].m;
    }

    void split(const size_t &x, const size_t &y) {
        makeRoot(x);
        access(y);
        splay(y);
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

    bool isConnected(const int &x, const int &y) {
        makeRoot(x);

        return x == findRoot(y);
    }

    const unsigned &id(const int x) {
        return tr[x].id;
    }

    const int &max(const int &x) {
        return tr[x].m;
    }
} lct;

int n, m, ans = std::numeric_limits<int>::max();

struct node {
    int x, y, a, b;
} q[M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> q[i].x >> q[i].y >> q[i].a >> q[i].b;
    }

    std::sort(q + 1, q + m + 1, [](const node &a, const node &b) {
        return a.a == b.a ? a.b < b.b : a.a < b.a;
    });

    for (int i = 1; i <= m; i++) {
        lct.set(i + n, q[i].b);

        if (q[i].x == q[i].y) continue;

        if (lct.isConnected(q[i].x, q[i].y)) {
            lct.split(q[i].x, q[i].y);

            int x = lct.id(q[i].y), y = lct.max(q[i].y);
            int a = q[x - n].x, b = q[x - n].y;

            if (y > q[i].b) {
                lct.cut(a, x);
                lct.cut(x, b);
                lct.link(q[i].x, i + n);
                lct.link(i + n, q[i].y);
            }
        } else {
            lct.link(q[i].x, i + n);
            lct.link(i + n, q[i].y);
        }

        if (lct.isConnected(1, n)) {
            ans = std::min(ans, lct.query(1, n) + q[i].a);
        }
    }

    cout << (ans == std::numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}
