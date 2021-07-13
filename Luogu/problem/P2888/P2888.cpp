#include <bits/stdc++.h>

using namespace std;

int n, m, t, s, e, h, a, b, f[305][305];

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : INT_MAX;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> s >> e >> h;
        f[s][e] = h;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
            }
        }
    }
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << (f[a][b] == INT_MAX ? -1 : f[a][b]) << endl;
    }
    return 0;
}
