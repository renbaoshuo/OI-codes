#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, f[105][105], ans[105];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        f[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j] != 0x3f3f3f3f && f[i][j] > 0) {
                ans[i]++;
                ans[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == n - 1) {
            ans[0]++;
        }
    }
    cout << ans[0] << endl;
    return 0;
}
