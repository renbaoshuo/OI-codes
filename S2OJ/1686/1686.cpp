#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = (1 << 8) + 5;
const int mod = 998244353;

int n, a[N], f[N], sum[M][M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 1;

        int s = a[i] >> 8,
            t = a[i] & ((1 << 8) - 1);

        for (int c = t;; c = (c - 1) & t) {
            f[i] = (f[i] + sum[s][c]) % mod;
            if (!c) break;
        }

        for (int c = s ^ ((1 << 8) - 1);; c = (c - 1) & (s ^ ((1 << 8) - 1))) {
            sum[s | c][t] = (sum[s | c][t] + f[i]) % mod;
            if (!c) break;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i] << endl;
    }

    return 0;
}
