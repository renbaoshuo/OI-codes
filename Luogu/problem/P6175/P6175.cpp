#include <bits/stdc++.h>

using namespace std;

long long n, m, u, v, d, f1[105][105], f2[105][105], ans = 0x3f3f3f3f;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f1[i][j] = f2[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> d;
        f1[u][v] = min(f1[u][v], d);
        f1[v][u] = min(f1[v][u], d);
        f2[u][v] = min(f2[u][v], d);
        f2[v][u] = min(f2[v][u], d);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ans = min(ans, f1[i][j] + f2[i][k] + f2[k][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k][j]);
                f1[j][i] = f1[i][j];
            }
        }
    }
    if (ans == 0x3f3f3f3f) {
        cout << "No solution." << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
