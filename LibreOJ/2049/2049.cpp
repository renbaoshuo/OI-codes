#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 2e5 + 5;

int n, m;
int cnt, dep[N], id[N], siz[N], fa[N], son[N], top[N];
std::vector<int> g[N];
std::tuple<int, int, int> tasks[M];

class Queue {
  private:
    std::priority_queue<int> q, r;

  public:
    Queue()
        : q(), r() {}

    int top() {
        while (!q.empty() && !r.empty() && q.top() == r.top()) q.pop(), r.pop();

        return q.empty() ? -1 : q.top();
    }

    void push(const int &val) {
        q.push(val);
    }

    void erase(const int &val) {
        r.push(val);
    }
};

struct node : public Queue {
    int l, r;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l),
          r(_r),
          Queue() {}
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

int query(int u, int x) {
    if (tr[u].l == tr[u].r) return tr[u].top();

    int mid = (tr[u].l + tr[u].r) >> 1,
        res = tr[u].top();

    if (x <= mid) res = std::max(res, query(u << 1, x));
    else res = std::max(res, query(u << 1 | 1, x));

    return res;
}

void push(int u, int l, int r, int v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].push(v);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) push(u << 1, l, r, v);
    if (r > mid) push(u << 1 | 1, l, r, v);
}

void erase(int u, int l, int r, int v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].erase(v);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) erase(u << 1, l, r, v);
    if (r > mid) erase(u << 1 | 1, l, r, v);
}

void dfs1(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u] = f;
    siz[u] = 1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);

        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    id[u] = ++cnt;
    top[u] = t;

    if (!son[u]) return;

    dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

        dfs2(v, v);
    }
}

void push_path(int u, int v, int val) {
    std::vector<std::pair<int, int>> qs;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        qs.emplace_back(id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);

    qs.emplace_back(id[v], id[u]);
    std::sort(qs.begin(), qs.end());

    int lst = 0;

    for (auto o : qs) {
        push(1, lst + 1, o.first - 1, val);
        lst = o.second;
    }

    if (qs.back().second < n) {
        push(1, qs.back().second + 1, n, val);
    }
}

void erase_path(int u, int v, int val) {
    std::vector<std::pair<int, int>> qs;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) std::swap(u, v);

        qs.emplace_back(id[top[u]], id[u]);
        u = fa[top[u]];
    }

    if (dep[u] < dep[v]) std::swap(u, v);

    qs.emplace_back(id[v], id[u]);
    std::sort(qs.begin(), qs.end());

    int lst = 0;

    for (auto o : qs) {
        erase(1, lst + 1, o.first - 1, val);
        lst = o.second;
    }

    if (qs.back().second < n) {
        erase(1, qs.back().second + 1, n, val);
    }
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

    dfs1(1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    for (int i = 1, op; i <= m; i++) {
        cin >> op;

        if (op == 0) {
            int a, b, v;

            cin >> a >> b >> v;

            tasks[i] = {a, b, v};

            push_path(a, b, v);
        } else if (op == 1) {
            int t, a, b, v;

            cin >> t;

            std::tie(a, b, v) = tasks[t];

            erase_path(a, b, v);
        } else {  // op == 2
            int x;

            cin >> x;

            cout << query(1, id[x]) << endl;
        }
    }

    return 0;
}
