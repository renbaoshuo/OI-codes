#include <bits/stdc++.h>

using namespace std;

int n, u, v, w[505], z[505], c[505], f[55][505][505];

int main() {
    cin >> u >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> z[i] >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = u; j > 0; j--) {
            for (int k = v; k > 0; k--) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= w[i] && k >= z[i]) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - w[i]][k - z[i]] + c[i]);
                }
            }
        }
    }
    cout << f[n][u][v] << endl;
    return 0;
}
