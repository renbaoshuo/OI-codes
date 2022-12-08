#include <iostream>
#include <algorithm>
#include <random>
#include <stack>
#include <tuple>

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
            sum;   // 权值和
        int key;   // 权值
        bool rev;  // 翻转标记

        node()
            : p(0), l(0), r(0), pre(0), val(0), sum(0), key(rand()), rev(false) {}
    } tr[N];

    void pushup(int u) {
        // 计算异或和
        tr[u].sum = tr[tr[u].l].sum + tr[u].val + tr[tr[u].r].sum;

        // 标记父亲节点
        if (tr[u].l) tr[tr[u].l].p = u;
        if (tr[u].r) tr[tr[u].r].p = u;
    }

    void pushdown(int u) {
        if (!tr[u].rev) return;

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
        if (!x || !y) return x | y;

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
        while (!st.empty()) st.pop();
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

    int query(int x, int y) {
        makeRoot(x);
        access(y);

        auto t = split(findRoot(y));
        int res = tr[t.first].sum - 1;
        merge(t.first, t.second);

        return res;
    }

    void set(int u, int val) {
        tr[u].sum = tr[u].val = val;
    }
} lct;

int type, n, q, fa[N], ans;
std::tuple<int, int, int> t[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    fa[x] = y;

    int a, b, c, d;

    std::tie(a, b, std::ignore) = t[x];
    std::tie(c, d, std::ignore) = t[y];

    t[y] = std::max({
                        t[x],
                        t[y],
                        std::make_tuple(a, c, lct.query(a, c)),
                        std::make_tuple(a, d, lct.query(a, d)),
                        std::make_tuple(b, c, lct.query(b, c)),
                        std::make_tuple(b, d, lct.query(b, d)),
                    },
                    [](const auto &a, const auto &b) {
                        return std::get<2>(a) < std::get<2>(b);
                    });
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> type >> n >> q;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        t[i] = std::make_tuple(i, i, 0);
        lct.set(i, 1);
    }

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int u, v;

            cin >> u >> v;

            if (type) u ^= ans, v ^= ans;

            lct.link(u, v);
            merge(u, v);
        } else {  // op == 2
            int u;

            cin >> u;

            if (type) u ^= ans;

            int x = find(u);
            ans = std::max(lct.query(u, std::get<0>(t[x])), lct.query(u, std::get<1>(t[x])));

            cout << ans << endl;
        }
    }

    return 0;
}
