#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const int mod = 1e4 + 7;

int a, b, k, n, m;
int fac[N], inv[N];

int binpow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }
    return res;
}

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    for (int i = 2; i <= 1000; i++) {
        inv[i] = static_cast<long long>(inv[i - 1]) * inv[i] % mod;
    }

    cin >> a >> b >> k >> n >> m;

    cout << static_cast<long long>(C(k, n)) * binpow(a, n) % mod * binpow(b, m) % mod << endl;

    return 0;
}
