#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, maxa, a[100005], num[100005];
long long ans;

long long C(long long x, long long k) {
    return (k == 1ll ? x : x * (x - 1ll) / 2ll) % mod;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        num[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (num[i] >= 2ll) {
            long long times = C(num[i], 2ll) % mod;
            for (int j = 1; j <= i / 2; ++j) {
                if (j != i - j && num[j] >= 1 && num[i - j] >= 1) {
                    ans += times * C(num[j], 1) * C(num[i - j], 1) % mod;
                }
                if (j == i - j && num[j] >= 2) {
                    ans += times * C(num[j], 2) % mod;
                }
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
