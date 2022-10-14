#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;
const int mod = 998244353;

int n, m, max, fac[N], inv[N], fac_inv[N];
std::unordered_map<int, int> map;

int binpow(int a, int b) {
    a %= mod;

    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(mod - mod / i) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        map[x]++;
        max = std::max(max, x);
    }

    for (int i = 1; i < max; i++) {
        cout << 0 << endl;
    }

    for (int k = max; k <= m; k++) {
        int res = 1;

        for (auto item : map) {
            res = static_cast<long long>(res) * binpow(C(k, item.first), item.second) % mod;
        }

        cout << res << endl;
    }

    return 0;
}
