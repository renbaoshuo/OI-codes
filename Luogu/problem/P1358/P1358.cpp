#include <bits/stdc++.h>

using namespace std;

long long n, m, t, f[10005][105], ans = 1;

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        f[i][0] = 1;
    }
    for (int i = 1; i <= min(n, m); i++) {
        f[i][i] = 1;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j <= 100; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % 10007;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> t;
        ans *= f[n][t];
        ans %= 10007;
        n -= t;
    }
    cout << ans << endl;
    return 0;
}
