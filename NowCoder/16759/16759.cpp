#include <bits/stdc++.h>

using namespace std;

int n, r, c, k, w[15][15], f[15][15][15][15];

int main() {
    cin >> n;
    while (cin >> r >> c >> k, r && c && k) {
        w[r][c] = k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    f[i][j][k][l] = max({f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]}) + w[i][j] + w[k][l];
                    if (i == k && j == l) f[i][j][k][l] -= w[i][j];
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
    return 0;
}
