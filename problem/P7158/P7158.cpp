#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int t, n, k;
long long f[100005], g[100005];

int main() {
    scanf("%d", &t);
    f[1] = 8;
    g[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        f[i] = (f[i - 1] * 9 + g[i - 1]) % mod;
        g[i] = (g[i - 1] * 9 + f[i - 1]) % mod;
    }
    while (t--) {
        scanf("%d%d", &n, &k);
        printf("%lld\n", n == 1 ? 9 : f[n]);
    }
    return 0;
}
