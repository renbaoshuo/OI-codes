#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, t, m, fa[N], sum[N], f[N], ans;
bool vis[N];
std::vector<int> g[N];

void dfs(int u, int _f) {
    int max1 = 0, max2 = 0;

    fa[u] = _f;

    if (u != t) {
        sum[u] = sum[_f] + g[u].size() - 1 - (u != m);
    }

    for (const int &v : g[u]) {
        if (v == _f) continue;

        dfs(v, u);

        if (f[v] > max1) {
            max2 = max1;
            max1 = f[v];
        } else if (f[v] > max2) {
            max2 = f[v];
        }
    }

    f[u] = max2 + g[u].size() - 1;
}

bool check(int x) {
    for (int i = m, cnt = 1; i != t; i = fa[i], cnt++) {
        int t = 0;

        for (const int &v : g[i]) {
            if (vis[v] || sum[i] + f[v] <= x) continue;
            if (!cnt) return false;

            t++, cnt--;
        }

        x -= t;
    }

    return x >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t >> m;

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(t, 0);

    for (int i = m; i; i = fa[i]) {
        vis[i] = true;
    }

    int l = 0, r = n << 1;

    while (l <= r) {
        int mid = l + r >> 1;

        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
