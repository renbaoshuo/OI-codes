#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005;

int n, m, s, t, in[N];
bool vis[N];
std::vector<int> c, g[N];
std::unordered_map<int, int> map[N];

void cycle() {
    std::queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (in[v] > 1) {
                if (--in[v] == 1) q.push(v);
            }
        }
    }
}

void dfs(int u, int fa, std::vector<int> &res) {
    if (vis[u]) return;
    vis[u] = true;

    res.push_back(u);

    for (int v : g[u]) {
        if (v == fa || u == s && v == t || v == s && u == t) continue;

        dfs(v, u, res);
    }

    vis[u] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++, in[v]++;

        map[u][v] = map[v][u] = true;
    }

    cycle();

    for (int i = 1; i <= n; i++) {
        std::sort(g[i].begin(), g[i].end());
        if (in[i] >= 2) c.push_back(i);
    }

    std::vector<int> ans;

    if (n == m) {
        ans = std::vector<int>(n, n);

        for (int i = 0; i < c.size(); i++) {
            for (int j = i + 1; j < c.size(); j++) {
                s = c[i], t = c[j];

                if (!map[s][t]) continue;

                std::vector<int> res;

                dfs(1, 0, res);

                ans = std::min(ans, res);
            }
        }
    } else {
        dfs(1, 0, ans);
    }

    for (int &ans : ans) {
        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}
