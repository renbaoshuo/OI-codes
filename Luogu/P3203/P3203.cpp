#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, a[N];

class LinkCutTree {
  private:
    struct node {
        size_t l, r, f;
        unsigned s;
        bool rev;

        node()
            : l(0), r(0), f(0), s(0), rev(false) {}

        node(size_t _f)
            : l(0), r(0), f(_f), s(1), rev(false) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N];

    inline void pushup(size_t u) {
        tr[u].s = tr[tr[u].l].s + 1 + tr[tr[u].r].s;
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
    unsigned query(int x, int y) {
        split(x, y);

        return tr[y].s;
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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        lct.link(i, std::min(i + a[i], n + 1));
    }

    cin >> m;

    while (m--) {
        int op, x, y;

        cin >> op;

        if (op == 1) {
            cin >> x;

            cout << lct.query(x + 1, n + 1) - 1 << endl;
        } else {  // op == 2
            cin >> x >> y;

            x++;
            lct.cut(x, std::min(x + a[x], n + 1));
            lct.link(x, std::min(x + (a[x] = y), n + 1));
        }
    }

    return 0;
}
