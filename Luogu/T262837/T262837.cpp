#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, color[N], ans;
int cnt, id[N];
bool vis[N];
std::vector<int> g[N];
std::unordered_set<int> p[N];

bool dfs1(int u, int c) {
    color[u] = c;

    for (int v : g[u]) {
        if (color[v]) {
            if (color[v] == c) return false;
        } else if (!dfs1(v, 3 - c)) {
            return false;
        }
    }

    return true;
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs1(i, 1)) return false;
        }
    }

    return true;
}

void dfs2(int u, int x) {
    id[u] = x;
    p[x].insert(u);

    for (int v : g[u]) {
        if (!id[v]) dfs2(v, x);
    }
}

int bfs(int x) {
    std::fill_n(vis, N, false);

    int res = 0;

    std::queue<std::pair<int, int>> q;

    q.emplace(x, 0);
    vis[x] = true;

    while (!q.empty()) {
        auto e = q.front();
        q.pop();

        int u = e.first,
            w = e.second;

        res = std::max(res, w);

        for (int v : g[u]) {
            if (vis[v]) continue;
            vis[v] = true;

            q.emplace(v, w + 1);
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if (!check()) {
        cout << -1 << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (!id[i]) dfs2(i, ++cnt);
    }

    for (int i = 1; i <= cnt; i++) {
        int res = 0;

        for (const int &x : p[i]) {
            res = std::max(res, bfs(x));
        }

        ans += res;
    }

    cout << ans << endl;

    return 0;
}
