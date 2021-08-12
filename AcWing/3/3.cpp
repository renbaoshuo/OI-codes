#include <bits/stdc++.h>

using namespace std;

int n, m, v[1005], w[1005], f[1005][1005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], j >= v[i] ? f[i][j - v[i]] + w[i] : f[i - 1][j]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
