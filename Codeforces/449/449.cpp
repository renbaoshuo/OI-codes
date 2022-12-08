#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e9 + 7;

int n, s[1 << 20], ans;

int binpow(int a, int b) {
    int res = 1;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        s[(1 << 20) - 1 - x]++;
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 1 << 20; j++) {
            if (j & (1 << i)) {
                s[j] += s[j ^ (1 << i)];
            }
        }
    }

    ans = binpow(2, n);

    for (int i = 0; i < (1 << 20) - 1; i++) {
        ans = (static_cast<long long>(ans) + (__builtin_popcount(i) % 2 ? -1 : 1) * binpow(2, s[i])) % mod;
    }

    cout << (ans + mod) % mod << endl;

    return 0;
}
