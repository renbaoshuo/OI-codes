#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, ans;
long long f[N];
std::vector<int> g[N];
std::pair<int, int> p[N];

void dfs(int u) {
    for (int v : g[u]) {
        dfs(v);

        f[u] += f[v];
    }

    if (f[u] < p[u].first) {
        ans++;
        f[u] = p[u].second;
    }

    f[u] = std::min(f[u], (long long)p[u].second);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        memset(f, 0x00, sizeof(f));
        ans = 0;

        cin >> n;

        for (int i = 2, x; i <= n; i++) {
            cin >> x;

            g[x].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
        }

        dfs(1);

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        cout << ans << endl;
    }

    return 0;
}
