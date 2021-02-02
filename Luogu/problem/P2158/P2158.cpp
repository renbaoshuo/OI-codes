#include <bits/stdc++.h>

using namespace std;

int n, ans, f[50000];

int main() {
    cin >> n;
    ans = (n - 1) * (n - 1);
    if(!--n) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = n; i >= 2; i--) {
        f[i] = (n / i) * (n / i);
        for (int j = 2 * i; j <= n; j += i) {
            f[i] -= f[j];
        }
        ans -= f[i];
    }
    cout << ans + 2 << endl;
    return 0;
}