#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m;
bool vis[N];
std::vector<int> g[N], a, b;

void check() {
    if (a.size() == n - a.size() - b.size()) {
        std::fill_n(vis, N, false);

        cout << b.size() << ' ' << a.size() << endl;

        for (const int &x : b) {
            cout << x << ' ';

            vis[x] = true;
        }

        cout << endl;

        for (const int &x : a) {
            cout << x << ' ';

            vis[x] = true;
        }

        cout << endl;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cout << i << ' ';
            }
        }

        cout << endl;

        exit(0);
    }
}

void dfs(int u) {
    vis[u] = true;
    b.emplace_back(u);
    check();

    for (const int &v : g[u]) {
        if (vis[v]) continue;

        dfs(v);
        check();
    }

    b.pop_back();
    a.emplace_back(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;

        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    cout << -1 << endl;

    return 0;
}
