#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int p, q, n, m, a[N], b[N], len, c[N], cnt, d[N], w[N], pos[N];
long long t, ans;
std::vector<int> g[N], s[N];

int dfs(int u, int c) {
    if (::c[u]) return 0;

    ::c[u] = c;
    g[c].emplace_back(u);
    return d[u] + dfs((u + p) % q, c);
}

int calc(int l, int x) {
    return s[c[x]][pos[x] + l] - s[c[x]][pos[x]];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> q >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    if (p > q) {
        std::swap(p, q);
        std::swap(n, m);
        std::swap(a, b);
    }

    len = q / std::__gcd(p, q);

    for (int i = 1; i <= m; i++) {
        d[b[i]] = 1;
    }

    for (int i = 0; i < q; i++) {
        if (!c[i]) {
            cnt++;
            w[cnt] = dfs(i, cnt);
        }
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            pos[g[i][j]] = j;
        }

        s[i] = g[i];

        for (int j = 0; j < g[i].size() - 1; j++) {
            s[i].emplace_back(g[i][j]);
        }

        std::transform(s[i].begin(), s[i].end(), s[i].begin(), [&](int x) -> int { return d[x]; });
        std::partial_sum(s[i].begin(), s[i].end(), s[i].begin());
    }

    for (int i = 1; i <= n; i++) {
        long long x = (t - 1 - a[i]) / p;

        ans += x / len * w[c[a[i]]];
        ans += static_cast<long long>(calc(x % len, a[i])) + d[a[i]];
    }

    cout << ans << endl;

    return 0;
}
