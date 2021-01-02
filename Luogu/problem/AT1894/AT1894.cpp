#include <bits/stdc++.h>

using namespace std;

long long n, k, a[100005], f[100005], ans;

int main() {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    for (long long i = k; i <= n; i++) {
        ans += f[i] - f[i - k];
    }
    cout << ans << endl;
    return 0;
}
