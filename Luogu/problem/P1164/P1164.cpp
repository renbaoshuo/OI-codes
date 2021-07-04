#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[10005], f[10005][10005];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == a[i]) {
                f[i][j] = f[i - 1][j] + 1;
            }
            if (j > a[i]) {
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            }
            if (j < a[i]) {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
