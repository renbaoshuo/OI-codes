#include <bits/stdc++.h>

using namespace std;

int n, k, ans, a[100005], f[100005];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    for (int i = k; i <= n; i++) {
        ans = max(ans, f[i] - f[i - k]);
    }
    cout << ans << endl;
    return 0;
}
