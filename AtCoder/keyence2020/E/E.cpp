#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 2e5 + 5;

int n, m, a[N], ans[M];
std::vector<std::pair<int, int>> g[N];
char c[N];
std::queue<int> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);

        if (a[u] == a[v] && !c[u] && !c[v]) {
            c[u] = 'W';
            c[v] = 'B';
            q.emplace(u);
            q.emplace(v);
            ans[i] = a[u];
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : g[u]) {
            int v = e.first,
                id = e.second;

            if (!c[v] && a[u] <= a[v]) {
                c[v] = c[u] == 'W' ? 'B' : 'W';
                ans[id] = a[v];
                q.emplace(v);
            }
        }
    }

    if (std::count(c + 1, c + 1 + n, '\0')) {
        cout << -1 << endl;

        exit(0);
    }

    cout << c + 1 << endl;

    for (int i = 1; i <= m; i++) {
        cout << (ans[i] ? ans[i] : 1000000000) << endl;
    }

    return 0;
}
