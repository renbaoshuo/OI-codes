#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 2e6 + 5;

int n, q, cnt, root, end[N], c[M];
std::vector<int> g[M];
int id[M], rid[M], fa[M], dep[M], siz[M], son[M], top[M];

struct node {
    int val;
    int child[26], fail;

    node()
        : val(0), fail(0) {
        std::fill(std::begin(child), std::end(child), 0);
    }
} tr[M];

void insert(std::string s, int id) {
    int cur = root;

    for (char c : s) {
        if (!tr[cur].child[c - 'a']) {
            tr[cur].child[c - 'a'] = ++cnt;
        }

        cur = tr[cur].child[c - 'a'];
    }

    end[id] = cur;
}

void build() {
    std::queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (tr[root].child[i]) {
            q.emplace(tr[root].child[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (tr[cur].child[i]) {
                tr[tr[cur].child[i]].fail = tr[tr[cur].fail].child[i];
                q.emplace(tr[cur].child[i]);
            } else {
                tr[cur].child[i] = tr[tr[cur].fail].child[i];
            }
        }
    }
}

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    son[u] = -1;

    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);
        siz[u] += siz[v];

        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    static int cnt = 0;

    rid[id[u] = ++cnt] = u;
    top[u] = t;

    if (~son[u]) dfs2(son[u], t);

    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;

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

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= M; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        std::string s;

        cin >> s;

        insert(s, i);
    }

    build();

    for (int i = 1; i <= cnt; i++) {
        g[tr[i].fail].emplace_back(i);
        g[i].emplace_back(tr[i].fail);
    }

    dfs1(0, 0);
    dfs2(0, 0);

    cin >> q;

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            std::string p;
            std::vector<int> v;

            cin >> p;

            int cur = root;

            for (char c : p) {
                cur = tr[cur].child[c - 'a'];
                v.emplace_back(cur);
            }

            std::sort(v.begin(), v.end(), [&](int x, int y) {
                return id[x] < id[y];
            });

            for (int x : v) {
                add(id[x], 1);
            }

            for (int i = 1; i < v.size(); i++) {
                add(id[lca(v[i - 1], v[i])], -1);
            }
        } else {  // op == 2
            int x;

            cin >> x;

            cout << sum(id[end[x]] + siz[end[x]] - 1) - sum(id[end[x]] - 1) << endl;
        }
    }

    return 0;
}
