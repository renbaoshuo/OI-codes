#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55 << 1;

int n, w[N], f[N][N], g[N][N], ans;
char op[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> w[i];
        w[n + i] = w[i];
        op[n + i] = op[i];
    }

    for (int i = 1; i <= (n << 1); i++) {
        f[i][i] = g[i][i] = w[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n * 2; l++, r++) {
            f[l][r] = std::numeric_limits<int>::min();
            g[l][r] = std::numeric_limits<int>::max();

            for (int k = l; k < r; k++) {
                int maxl = f[l][k], maxr = f[k + 1][r];
                int minl = g[l][k], minr = g[k + 1][r];

                if (op[k + 1] == 't') {
                    f[l][r] = std::max(f[l][r], maxl + maxr);
                    g[l][r] = std::min(g[l][r], minl + minr);
                } else {
                    int x1 = minl * minr,
                        x2 = minl * maxr,
                        x3 = maxl * minr,
                        x4 = maxl * maxr;
                    f[l][r] = std::max({f[l][r], x1, x2, x3, x4});
                    g[l][r] = std::min({g[l][r], x1, x2, x3, x4});
                }
            }
        }
    }

    ans = std::numeric_limits<int>::min();
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, f[i][n + i - 1]);
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        if (ans == f[i][i + n - 1]) {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}
