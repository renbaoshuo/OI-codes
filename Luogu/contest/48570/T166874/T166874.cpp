#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
long long t, n, k, k1, k2;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        k1 = k + 1 >> 1;
        k2 = k >> 1;
        cout << 1ll * (((((n * (n + 1)) / 2 % mod * k1 % mod) - (((k1 - 1) * k1) / 2 % mod) % mod) + ((((n - 1) * n) / 2 % mod * k2 % mod) - ((k2 - 1) * k2) / 2) % mod) % mod + mod) % mod << endl;
    }
    return 0;
}
