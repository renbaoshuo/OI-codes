#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
long long n, ans, a[500005], b[500005], sa[500005], sb[500005], q[500005], qa[500005], qb[500005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sa[i] = (sa[i - 1] + a[i]) % mod;
        qa[i] = (qa[i - 1] + sa[i]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sb[i] = (sb[i - 1] + b[i]) % mod;
        qb[i] = (qb[i - 1] + sb[i]) % mod;
        q[i] = (q[i - 1] + sa[i] * sb[i] % mod) % mod;
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + ((q[n] - q[i - 1] + mod) % mod) - (((qb[n] - qb[i - 1] + mod) % mod * sa[i - 1]) % mod) - (((qa[n] - qa[i - 1] + mod) % mod * sb[i - 1]) % mod) + (((n - i + 1) * ((sa[i - 1] * sb[i - 1]) % mod)) % mod) + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
