#include <bits/stdc++.h>

using namespace std;

int n, m, t, mi[205], ti[205], f[205][205];

int main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> mi[i] >> ti[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= mi[i]; j--) {
            for (int k = t; k >= ti[i]; k--) {
                f[j][k] = max(f[j][k], f[j - mi[i]][k - ti[i]] + 1);
            }
        }
    }
    cout << f[m][t] << endl;
    return 0;
}
