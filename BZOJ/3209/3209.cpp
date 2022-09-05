#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 70;
const int mod = 1e7 + 7;

long long n, f[N][N][2], ans = 1;

long long binpow(long long a, long long b) {
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

    cin >> n;

    std::bitset<64> b(n);

    n = 64 - __builtin_clzll(n) - 1 + 1;
    b <<= 1;

    f[0][0][1] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i + 1][j][0] += f[i][j][0];
            f[i + 1][j + 1][0] += f[i][j][0];
            f[i + 1][j][(b[i + 1] == 0)] += f[i][j][1];
            if (b[i + 1] == 1) f[i + 1][j + 1][1] += f[i][j][1];
        }
    }

    for (int i = 1; i <= 64; i++) {
        ans = ans * binpow(i, f[n][i][0] + f[n][i][1]) % mod;
    }

    cout << ans << endl;

    return 0;
}
