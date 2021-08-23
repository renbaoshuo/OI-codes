#include <bits/stdc++.h>

using namespace std;

int n, k, a;
long long sum[5000005], f[5000005], now = INT_MIN;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1];
        if (i - k >= 0) {
            now = max(now, f[i - k] - sum[i - k]);
            f[i] = max(f[i], now + sum[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}
