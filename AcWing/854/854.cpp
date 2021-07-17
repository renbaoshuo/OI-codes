#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, y, z, f[205][205];

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : 0x3f3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        f[x][y] = min(f[x][y], z);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        if (f[x][y] > 0x1fffffff) {
            cout << "impossible" << endl;
        } else {
            cout << f[x][y] << endl;
        }
    }
    return 0;
}
