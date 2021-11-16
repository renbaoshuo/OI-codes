#include <bits/stdc++.h>

using namespace std;

int n, m, f[1005][1005];
string a, b;

int main() {
    cin >> n >> m >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
