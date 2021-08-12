#include <bits/stdc++.h>

using namespace std;

int n, x, lose[1005], win[1005], use[1005], f[1005];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            f[j] = max(f[j] + lose[i], j >= use[i] ? f[j - use[i]] + win[i] : f[j] + lose[i]);
        }
    }
    cout << 5ll * f[x] << endl;
    return 0;
}
