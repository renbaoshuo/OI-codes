#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5,
          K = 1e8 + 5;

int n, m, query[N];
int root, siz[N], max[N];
int cnt, dist[N];
bool vis[N], exists[K], ans[N];
std::vector<std::pair<int, int>> g[N];

void find(int u, int fa, int tot) {
    siz[u] = 1;
    max[u] = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa || vis[v]) continue;

        find(v, u, tot);

        siz[u] += siz[v];
        max[u] = std::max(max[u], siz[v]);
    }

    max[u] = std::max(max[u], tot - siz[u]);

    if (max[u] < max[root]) root = u;
}

void dis(int u, int fa, int sum) {
    dist[++cnt] = sum;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa || vis[v]) continue;

        dis(v, u, sum + w);
    }
}

void calc(int u) {
    std::queue<int> q;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (vis[v]) continue;

        cnt = 0;
        dis(v, u, w);

        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= m; j++) {
                if (query[j] >= dist[i]) {
                    ans[j] |= exists[query[j] - dist[i]];
                }
            }
        }

        for (int i = 1; i <= cnt; i++) {
            q.push(dist[i]);
            exists[dist[i]] = true;
        }
    }

    while (!q.empty()) {
        exists[q.front()] = false;
        q.pop();
    }
}

void solve(int u) {
    vis[u] = true;
    exists[0] = true;
    calc(u);

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (vis[v]) continue;

        max[root = 0] = std::numeric_limits<int>::max();
        find(v, 0, siz[v]);
        solve(root);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    for (int i = 1; i <= m; i++) {
        cin >> query[i];
    }

    cnt = 0;
    max[root = 0] = n;
    find(1, 0, n);
    solve(root);

    for (int i = 1; i <= m; i++) {
        cout << (ans[i] ? "AYE" : "NAY") << endl;
    }

    return 0;
}
