#include <iostream>
#include <algorithm>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 65;
const int mod = 1e7 + 7;

long long n, f[N][N][2], ans = 1;
std::bitset<65> b;

long long binpow(long long a, long long b) {
    a %= mod;

    long long res = 1;

    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < 64; i++) {
        b.set(64 - i, (n >> i) & 1);
    }

    f[0][0][1] = 1;

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j <= i; j++) {
            f[i + 1][j][0] += f[i][j][0];
            f[i + 1][j + 1][0] += f[i][j][0];
            f[i + 1][j][(b[i + 1] == 0)] += f[i][j][1];
            if (b[i + 1] == 1)
                f[i + 1][j + 1][1] += f[i][j][1];
        }
    }

    for (int i = 1; i <= 64; i++) {
        ans = ans * binpow(i, f[64][i][0] + f[64][i][1]) % mod;
    }

    cout << ans << endl;

    return 0;
}
