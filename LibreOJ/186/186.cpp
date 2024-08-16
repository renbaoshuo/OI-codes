#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

// Link-Cut Tree
class LinkCutTree {
  private:
    std::stack<bool> st;

    struct node {
        int p,  // 父亲节点
            l,  // 左儿子
            r;  // 右儿子
        int pre;
        int val,   // 节点值
            sum;   // 异或和
        int key;   // 权值
        bool rev;  // 翻转标记

        node()
            : p(0), l(0), r(0), pre(0), val(0), sum(0), key(rand()), rev(false) {}
    } tr[N];

    void pushup(int u) {
        // 计算异或和
        tr[u].sum = tr[tr[u].l].sum ^ tr[u].val ^ tr[tr[u].r].sum;

        // 标记父亲节点
        if (tr[u].l)
            tr[tr[u].l].p = u;
        if (tr[u].r)
            tr[tr[u].r].p = u;
    }

    void pushdown(int u) {
        if (!tr[u].rev)
            return;

        tr[u].rev = false;
        std::swap(tr[u].l, tr[u].r);
        tr[tr[u].l].rev ^= 1;
        tr[tr[u].r].rev ^= 1;
    }

    std::pair<int, int> split(int u) {
        if (st.empty()) {
            pushdown(u);
            auto t = std::make_pair(u, tr[u].r);
            tr[u].r = 0;
            pushup(u);

            return t;
        }

        bool d = st.top() ^ tr[u].rev;
        st.pop();

        pushdown(u);

        if (d) {
            auto t = split(tr[u].l);
            tr[u].l = t.second;
            pushup(u);

            return std::make_pair(t.first, u);
        }

        auto t = split(tr[u].r);
        tr[u].r = t.first;
        pushup(u);

        return std::make_pair(u, t.second);
    }

    // 合并
    int merge(int x, int y) {
        if (!x || !y)
            return x | y;

        if (tr[x].key < tr[y].key) {
            pushdown(x);
            tr[x].r = merge(tr[x].r, y);
            pushup(x);
            return x;
        }

        pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }

    // 是否是根节点
    bool isRoot(int u) {
        return !tr[u].p || (tr[tr[u].p].l != u && tr[tr[u].p].r != u);
    }

    // 查找根节点
    int findRoot(int u) {
        while (!st.empty())
            st.pop();
        while (!isRoot(u)) {
            st.push(tr[tr[u].p].l == u);
            u = tr[u].p;
        }
        return u;
    }

    int findLeft(int u) {
        u = findRoot(u);
        pushdown(u);
        while (tr[u].l) {
            u = tr[u].l;
            pushdown(u);
        }
        return u;
    }

    int access(int u) {
        int lst = 0;

        while (u) {
            auto t = split(findRoot(u));
            tr[findLeft(lst)].pre = 0;
            lst = merge(t.first, lst);
            tr[findLeft(t.second)].pre = u;
            u = tr[findLeft(lst)].pre;
        }

        return lst;
    }

    void makeRoot(int u) {
        tr[access(u)].rev ^= 1;
    }

  public:
    int getRoot(int u) {
        return findLeft(access(u));
    }

    void link(int x, int y) {
        makeRoot(x);
        tr[x].pre = y;
    }

    void cut(int x, int y) {
        makeRoot(x);
        access(y);
        access(x);
        tr[y].pre = 0;
    }

    int query(int x, int y) {
        makeRoot(x);
        access(y);

        auto t = split(findRoot(y));
        int res = tr[t.first].sum;
        merge(t.first, t.second);

        return res;
    }

    void change(int u, int val) {
        makeRoot(u);
        auto t = split(findRoot(u));
        tr[u].val = val;
        merge(t.first, t.second);
    }

    void set(int u, int val) {
        tr[u].sum = tr[u].val = val;
    }
} lct;

int n, m;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        lct.set(i, x);
    }

    while (m--) {
        int op, x, y;

        cin >> op >> x >> y;

        switch (op) {
            case 0: {
                cout << lct.query(x, y) << endl;

                break;
            }
            case 1: {
                if (lct.getRoot(x) != lct.getRoot(y)) {
                    lct.link(x, y);
                }

                break;
            }
            case 2: {
                lct.cut(x, y);

                break;
            }
            case 3: {
                lct.change(x, y);

                break;
            }
        }
    }

    return 0;
}
