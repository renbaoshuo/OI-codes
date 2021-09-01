#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
bool f[405];
bitset<405> g[405];
pair<int, int> e[50005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].first >> e[i].second;
    }
    for (int i = 1; i <= n; i++) {
        g[i][i] = true;
        for (int j = m; j > 0; j--) {
            if (g[i][e[j].first] && g[i][e[j].second]) {
                f[i] = true;
                break;
            }
            if (g[i][e[j].first] || g[i][e[j].second]) {
                g[i][e[j].first] = g[i][e[j].second] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (!f[j] && !(g[i] & g[j]).count()) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
