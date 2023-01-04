#include <iostream>
#include <functional>
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

        int ans = 0;
        std::vector<int> tag(n, -1), match(n, -1);
        std::vector<std::vector<int>> g(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0, x; j < n; j++) {
                cin >> x;

                if (x) g[i].emplace_back(j);
            }
        }

        std::function<bool(int, int)> dfs = [&](int u, int t) {
            if (tag[u] == t) return false;

            tag[u] = t;

            for (int v : g[u]) {
                if (match[v] == -1 || dfs(match[v], t)) {
                    match[v] = u;

                    return true;
                }
            }

            return false;
        };

        for (int i = 0; i < n; i++) {
            if (dfs(i, i)) ans++;
        }

        cout << (ans == n ? "Yes" : "No") << endl;
    }

    return 0;
}
