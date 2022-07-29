#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e9 + 7;

const int N = 70;

int t;
long long n, s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < 64; i++) {
        long long x = ((1ll << i) - 1) % mod;

        s[i] = (s[i - 1] + x * (x + 1) / 2) % mod;
    }

    cin >> t;

    while (t--) {
        cin >> n;

        int x = 64 - __builtin_clzll(n) - 1;

        n = (n - (1ll << x)) % mod;

        cout << ((s[x - 1] << 1) % mod + n * (n + 1) % mod) % mod << endl;
    }

    return 0;
}
