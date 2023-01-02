#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;

class LinkCutTree {
  private:
    struct node {
        size_t l, r, f;
        bool rev;

        node(const size_t &_f = 0)
            : l(0), r(0), f(_f), rev(false) {}

        size_t &child(unsigned x) {
            return !x ? l : r;
        }
    } tr[N];

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

    int n, m;

    cin >> n >> m;

    while (m--) {
        std::string op;
        int u, v;

        cin >> op >> u >> v;

        if (op == "Connect") {
            lct.link(u, v);
        } else if (op == "Destroy") {
            lct.cut(u, v);
        } else {  // op == "Query"
            cout << (lct.check(u, v) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
