#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 998244353;

int n, w[N], ans = 1;

int binpow(int a, int b, int m) {
    int res = 1;

    a %= m;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % m;
        a = static_cast<long long>(a) * a % m;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 2; i <= n; i++) {
        ans = (static_cast<long long>(ans)
               + static_cast<long long>(w[i]) * binpow(w[i] + w[1], mod - 2, mod) % mod)
            % mod;
    }

    cout << ans << endl;

    return 0;
}
