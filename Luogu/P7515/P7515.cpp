#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int MAX = 1e6;

void solve() {
    int n, m;

    cin >> n >> m;

    std::vector<std::vector<int>>
        a(n, std::vector<int>(m, 0)),
        b(n - 1, std::vector<int>(m - 1, 0));
    std::vector<std::vector<std::pair<int, int>>>
        g(n + m, std::vector<std::pair<int, int>>());

    for (auto &i : b) {
        for (auto &x : i) {
            cin >> x;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            a[i][j] = b[i][j] - a[i + 1][j] - a[i + 1][j + 1] - a[i][j + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) & 1) {
                g[i].emplace_back(j + n, a[i][j]);
                g[j + n].emplace_back(i, MAX - a[i][j]);
            } else {
                g[j + n].emplace_back(i, a[i][j]);
                g[i].emplace_back(j + n, MAX - a[i][j]);
            }
        }
    }

    std::vector<long long> dist(n + m);

    auto spfa = [&]() -> bool {
        std::queue<int> q;
        std::vector<bool> vis(n + m, true);
        std::vector<int> cnt(n + m);

        for (int i = 0; i < n + m; i++) {
            q.emplace(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            vis[u] = false;

            for (auto e : g[u]) {
                int v = e.first,
                    w = e.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;

                    if (!vis[v]) {
                        if (++cnt[v] > n + m) return false;

                        vis[v] = true;
                        q.emplace(v);
                    }
                }
            }
        }

        return true;
    };

    if (!spfa()) {
        cout << "NO" << endl;

        return;
    }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] + ((i + j) & 1 ? dist[i] - dist[j + n] : dist[j + n] - dist[i]) << ' ';
        }

        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}
