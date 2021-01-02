#include <bits/stdc++.h>

using namespace std;

int n, m, v[30005], w[30005], f[30][30005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= v[i]) {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            }
            else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << f[m][n] << endl;
    return 0;
}
