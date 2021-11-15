#include <bits/stdc++.h>

using namespace std;

int n, g[505][505], f[505][505], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }
    memset(f, 0xc0, sizeof(f));
    f[1][1] = g[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + g[i][j];
        }
    }
    ans = 0xc0c0c0c0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}
