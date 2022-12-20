#include <iostream>
#include <cassert>
#include <functional>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

class SegmentTree {
  private:
    int L, R;

    static bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    }

    struct node {
        std::pair<int, int> o;
        node *lchild, *rchild;

        node()
            : o(0, 0), lchild(nullptr), rchild(nullptr) {}

        void pushup() {
            o = {0, 0};

            if (lchild) o = std::max(o, lchild->o, cmp);
            if (rchild) o = std::max(o, rchild->o, cmp);
        }
    };

    node *root;

    void modify(node *&cur, int l, int r, int pos, int val) {
        if (!cur) cur = new node();

        if (l == r) {
            cur->o.first += val;
            cur->o.second = l;

            return;
        }

        int mid = l + r >> 1;

        if (pos <= mid) modify(cur->lchild, l, mid, pos, val);
        else modify(cur->rchild, mid + 1, r, pos, val);

        cur->pushup();
    }

    std::pair<int, int> query(node *cur, int l, int r, int ql, int qr) {
        if (!cur) return {0, 0};
        if (ql <= l && r <= qr) return cur->o;

        int mid = l + r >> 1;
        std::pair<int, int> res;

        if (ql <= mid) res = std::max(res, query(cur->lchild, l, mid, ql, qr), cmp);
        if (qr > mid) res = std::max(res, query(cur->rchild, mid + 1, r, ql, qr), cmp);

        return res;
    }

    node *merge(node *&cur_a, node *&cur_b, int l, int r) {
        if (!cur_a) return cur_b;
        if (!cur_b) return cur_a;

        node *cur = new node();

        if (l == r) {
            cur->o.first = cur_a->o.first + cur_b->o.first;
            cur->o.second = l;

            delete cur_a;
            delete cur_b;
            cur_a = cur_b = nullptr;

            return cur;
        }

        int mid = l + r >> 1;

        cur->lchild = merge(cur_a->lchild, cur_b->lchild, l, mid);
        cur->rchild = merge(cur_a->rchild, cur_b->rchild, mid + 1, r);

        delete cur_a;
        delete cur_b;
        cur_a = cur_b = nullptr;

        cur->pushup();

        return cur;
    }

    void _delete(node *&cur) {
        if (cur->lchild) _delete(cur->lchild);
        if (cur->rchild) _delete(cur->rchild);
        delete cur;
    }

  public:
    SegmentTree(const int &_L = 0, const int _R = 0)
        : L(_L), R(_R), root(nullptr) {}

    ~SegmentTree() {
        // if (root) _delete(root);
    }

    void modify(int pos, int val) {
        modify(root, L, R, pos, val);
    }

    std::pair<int, int> query(int ql, int qr) {
        return query(root, L, R, ql, qr);
    }

    void merge(SegmentTree &b) {
        assert(L == b.L && R == b.R);

        root = merge(root, b.root, L, R);
    }
};

int n, m, x[N], y[N], z[N], max, ans[N];
int fa[N], dep[N], siz[N], son[N], top[N];
std::vector<int> g[N];

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    fa[u] = f;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);

        siz[u] += siz[v];

        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u]) continue;
        if (v == son[u]) continue;

        dfs2(v, v);
    }
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }

    return dep[u] < dep[v] ? u : v;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);

    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z[i];

        max = std::max(max, z[i]);
    }

    std::vector<SegmentTree> tr(n + 1, SegmentTree(1, max));

    for (int i = 1; i <= m; i++) {
        int p = lca(x[i], y[i]);

        tr[x[i]].modify(z[i], 1);
        tr[y[i]].modify(z[i], 1);
        tr[p].modify(z[i], -1);
        if (fa[p]) tr[fa[p]].modify(z[i], -1);
    }

    std::function<void(int)> dfs = [&](int u) {
        for (int v : g[u]) {
            if (v == fa[u]) continue;

            if (dep[v] > dep[u]) {
                dfs(v);

                tr[u].merge(tr[v]);
            }
        }

        auto res = tr[u].query(1, max);

        if (res.second) ans[u] = res.second;
    };

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
