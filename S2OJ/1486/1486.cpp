#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5,
          K = 55;
const int mod = 1e9 + 7;

int m, k, d, cnt;
long long f[K][K], p[N][K], s[N][K], sum;

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

    cin >> m >> k;

    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        f[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
        }
    }

    while (m--) {
        int op;

        cin >> op;

        if (op == 0) {
            int x;

            cin >> x;

            p[++cnt][0] = 1;
            s[cnt][0] = (s[cnt - 1][0] + p[cnt][0]) % mod;

            for (int i = 1; i <= k; i++) {
                p[cnt][i] = (p[cnt][i - 1] * (x - d) % mod + mod) % mod;
                s[cnt][i] = (s[cnt - 1][i] + p[cnt][i]) % mod;
            }

            sum = (sum + binpow(x, k)) % mod;
        } else {  // op == 1
            d++;

            sum = 0;
            for (int i = 0; i <= k; i++) {
                sum = (sum + f[k][i] * binpow(d, i) % mod * s[cnt][k - i] % mod) % mod;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
