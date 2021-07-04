#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, a[205][205], f[205];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
        }
        f[i] = 0x3f3f3f;
    }
    f[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            f[i] = min(f[i], f[j] + a[i][j]);
        }
    }
    cout << f[1] << endl;
    return 0;
}
