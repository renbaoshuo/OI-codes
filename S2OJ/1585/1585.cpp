#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;
const int mod = 998244353;

int n, k, a[N], f[N][N][N], g[N][N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 0; i <= k; i++) {
        g[0][0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= k; l++) {
                int p = std::min(a[i] - a[i - 1] + l, k);
                if (p < 0) continue;

                if (l <= j) {
                    f[i][j][l] = (f[i][j][l] + g[i - 1][j - l][p]) % mod;
                }

                g[i][j][l] = (f[i][j][l] + (l ? g[i][j][l - 1] : 0)) % mod;
            }
        }
    }

    cout << g[n][k][k] << endl;

    return 0;
}
