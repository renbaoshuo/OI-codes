#include <bits/stdc++.h>

using namespace std;

int n, x, y, z, f[12][12][12][12], a[12][12];

int main() {
    cin >> n;
    while (cin >> x >> y >> z, x || y || z) {
        a[x][y] = z;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int p = 1; p <= n; p++) {
                    f[i][j][k][p] = max({f[i - 1][j][k - 1][p], f[i - 1][j][k][p - 1], f[i][j - 1][k - 1][p], f[i][j - 1][k][p - 1]}) + a[i][j] + a[k][p];
                    if (i == k && p == j) {
                        f[i][j][k][p] -= a[i][j];
                    }
                }
            }
        }
    }
    cout << f[n][n][n][n] << endl;
    return 0;
}
