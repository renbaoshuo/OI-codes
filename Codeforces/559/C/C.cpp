#include <iostream>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int h, w, n, f[N];
int fac[N << 1], inv[N << 1], fac_inv[N << 1];
std::pair<int, int> a[N];

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < N << 1; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N << 1; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N << 1; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> h >> w >> n;

    for (int i = 1, r, c; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n);

    a[n + 1] = std::make_pair(h, w);
    for (int i = 1; i <= n + 1; i++) {
        f[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);

        for (int j = 1; j < i; j++) {
            f[i] = (f[i] - static_cast<long long>(f[j]) * C(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first)) % mod;
        }
    }

    cout << (f[n + 1] + mod) % mod << endl;

    return 0;
}
