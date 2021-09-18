#include <bits/stdc++.h>

using namespace std;

int n, m, f[2][55];
long long ans;
bool g[55][55];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[0][i] += g[i][j];
            f[1][j] += g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += (long long)pow(2, f[0][i]) - 1;
        ans += (long long)pow(2, m - f[0][i]) - 1;
    }
    for (int i = 1; i <= m; i++) {
        ans += (long long)pow(2, f[1][i]) - 1;
        ans += (long long)pow(2, n - f[1][i]) - 1;
    }
    cout << ans - n * m << endl;
    return 0;
}
