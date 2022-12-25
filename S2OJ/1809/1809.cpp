#include <iostream>
#include <functional>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        std::vector<int> c(n + 1), f(n + 1);
        std::set<int> ans;
        std::vector<std::vector<int>> g(n + 1);

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            g[x].emplace_back(i);
        }

        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        std::function<void(int)> dfs = [&](int u) -> void {
            if (g[u].empty()) {
                if (c[u] == 0) f[u] = 1;
                else if (c[u] == 1) f[u] = -1;

                return;
            }

            for (int v : g[u]) {
                dfs(v);

                if (f[v] > 0) f[u]++;
                else if (f[v] < 0) f[u]--;
            }
        };

        dfs(1);

        if (f[1] > 0) {
            for (int i = 1; i <= n; i++) {
                if (g[i].empty() && c[i] == -1) {
                    ans.emplace(i);
                }
            }

            cout << ans.size() << ' ';

            for (int x : ans) cout << x << ' ';

            cout << endl;
        } else if (f[1] == 0) {
            std::function<void(int)> dfs = [&](int u) -> void {
                if (g[u].empty()) {
                    if (c[u] == -1) {
                        ans.emplace(u);
                    }

                    return;
                }

                for (int v : g[u]) {
                    if (f[v] == 0 || f[v] == -1) {
                        dfs(v);
                    }
                }
            };

            dfs(1);

            cout << ans.size() << ' ';

            for (int x : ans) cout << x << ' ';

            cout << endl;
        } else {  // f[1] < 0
            cout << -1 << endl;
        }
    }

    return 0;
}
