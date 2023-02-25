#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, a[N], b[N];
long long ans1, ans2, ans3;

long long binpow(long long a, long long b, long long mod = ::mod) {
    a %= mod;

    long long res = 1;

    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        b[n - i + 1] = a[i];
    }

    long long x = binpow(2, m - 1);

    for (int i = 1; i <= n; i++) {
        ans1 = (((ans1 + static_cast<long long>(a[i]) * ((static_cast<long long>(x + 1) * n - i + 1) % mod + mod % mod) % mod * x) % mod) + mod) % mod;
    }

    for (int i = 1; i <= n; i++) {
        ans2 = (((ans2 + static_cast<long long>(b[i]) * ((static_cast<long long>(x + 1) * n - i + 1) % mod + mod % mod) % mod * x) % mod) + mod) % mod;
    }

    for (int i = 1; i <= n; i++) {
        ans3 = (((ans3 + static_cast<long long>(a[i]) * ((static_cast<long long>(x) * n - i + 1) % mod + mod % mod) % mod * x) % mod) + mod) % mod;
    }

    cout << std::max(((ans1 + ans3) % mod + mod) % mod, ((ans2 + ans3) % mod + mod) % mod) << endl;

    return 0;
}
