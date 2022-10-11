#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e6 + 5;

int n, p, _k, k, a[N], b[N], s[N], ans;

int binpow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % p;
        a = static_cast<long long>(a) * a % p;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> _k;

    s[0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        s[i] = static_cast<long long>(s[i - 1]) * a[i] % p;
    }

    b[n + 1] = binpow(s[n], p - 2);

    for (int i = n; i; i--) {
        b[i] = static_cast<long long>(b[i + 1]) * a[i] % p;
    }

    k = _k;

    for (int i = 1; i <= n; i++) {
        ans = (ans + static_cast<long long>(s[i - 1]) * b[i + 1] % p * k) % p;
        k = static_cast<long long>(k) * _k % p;
    }

    cout << ans << endl;

    return 0;
}
