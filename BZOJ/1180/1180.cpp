#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e4 + 5;

class LinkCutTree {
  private:
    struct node {
        size_t l, r, f;
        unsigned v, s;
        bool rev;

        node()
            : l(0), r(0), f(0), s(0), v(0), rev(false) {}

        node(unsigned _v, size_t _f)
            : l(0), r(0), f(_f), s(_v), v(_v), rev(false) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N];

    inline void pushup(size_t u) {
        tr[u].s = tr[tr[u].l].s + tr[u].v + tr[tr[u].r].s;
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
    void set(int p, int v) {
        tr[p].s = tr[p].v = v;
    }

    unsigned query(int x, int y) {
        split(x, y);

        return tr[y].s;
    }

    bool check(int x, int y) {
        return findRoot(x) == findRoot(y);
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

    void change(int p, int v) {
        access(p);
        splay(p);
        tr[p].v = v;
        pushup(p);
    }
} lct;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        lct.set(i, x);
    }

    int q;

    cin >> q;

    while (q--) {
        std::string op;
        int x, y;

        cin >> op >> x >> y;

        if (op == "bridge") {
            if (lct.check(x, y)) {
                cout << "no" << endl;
            } else {
                lct.link(x, y);

                cout << "yes" << endl;
            }
        } else if (op == "penguins") {
            lct.change(x, y);
        } else {  // op == "excursion"
            if (lct.check(x, y)) {
                cout << lct.query(x, y) << endl;
            } else {
                cout << "impossible" << endl;
            }
        }
    }

    return 0;
}
