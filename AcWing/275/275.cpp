#include <bits/stdc++.h>

using namespace std;

int n, m, w[55][55], f[55][55][55][55];

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = i + 1; k <= m; k++) {
                for (int l = 1; l < j; l++) {
                    f[i][j][k][l] = max({f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]}) + w[i][j] + w[k][l];
                    if (i == j && k == l) f[i][j][k][l] -= w[i][j];
                }
            }
        }
    }
    cout << f[m - 1][n][m][n - 1] << endl;
    return 0;
}
