#include <bits/stdc++.h>

using namespace std;

int n, w[105][105], f[105][105];

int main() {
    memset(f, 0x3f, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                f[i][j] = w[i][j];
            } else {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + w[i][j];
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
