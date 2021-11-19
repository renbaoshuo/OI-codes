#include <bits/stdc++.h>

using namespace std;

const long long N = 6000010;
const long long mod = 1000000007;

long long n, m, k, t;
long long ans, powk[N], vis[N], f[N], pri[N], tot;

long long qpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void euler(long long n) {
    f[1] = 1;
    vis[1] = 1;
    for (long long i = 2; i <= n; i++) {
        if (!vis[i]) pri[++tot] = i, f[i] = (powk[i] - 1 + mod) % mod;
        for (long long j = 1; j <= tot && i * pri[j] <= n; ++j) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                f[i * pri[j]] = f[i] * powk[pri[j]] % mod;
                break;
            } else {
                f[i * pri[j]] = f[i] * f[pri[j]] % mod;
            }
        }
    }
}

int main() {
    cin >> t >> k;
    for (long long i = 1; i <= 5000000; i++) {
        powk[i] = qpow(i, k);
    }
    euler(5000000);
    for (long long i = 1; i <= 5000000; i++) {
        f[i] = (f[i] + f[i - 1]) % mod;
    }
    while (t--) {
        cin >> n >> m;
        ans = 0;
        for (long long l = 1, r; l <= min(n, m); l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += (n / l) * (m / l) % mod * ((f[r] - f[l - 1] + mod) % mod) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}