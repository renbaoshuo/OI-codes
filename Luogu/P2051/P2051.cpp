#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const int mod = 9999973;

int n, m;
long long f[N][N][N]{1}, ans;

long long C(long long x) {
    return x * (x - 1) / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        // 不增加炮
        for (int j = 0; j <= m; j++) {
            for (int k = 0; j + k <= m; k++) {
                f[i][j][k] = f[i - 1][j][k];
            }
        }

        // 增加 1 个炮
        //
        // 从 1 个炮增加到 2 个炮
        for (int j = 0; j <= m; j++) {
            for (int k = 1; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j + 1][k - 1] * (j + 1) % mod) % mod;
            }
        }

        // 增加 1 个炮
        //
        // 从 0 个炮增加到 1 个炮
        for (int j = 1; j <= m; j++) {
            for (int k = 0; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * (m - j - k + 1) % mod) % mod;
            }
        }

        // 增加 2 个炮
        //
        // 一列从 0 个炮增加到 1 个炮
        // 一列从 1 个炮增加到 2 个炮
        for (int j = 0; j <= m; j++) {
            for (int k = 1; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1] * j * (m - j - k + 1) % mod) % mod;
            }
        }

        // 增加 2 个炮
        //
        // 两列从 0 个炮增加到 1 个炮
        for (int j = 2; j <= m; j++) {
            for (int k = 0; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k] * C(m - j - k + 2) % mod) % mod;
            }
        }

        // 增加 2 个炮
        //
        // 两列从 1 个炮增加到 2 个炮
        for (int j = 0; j <= m; j++) {
            for (int k = 2; j + k <= m; k++) {
                f[i][j][k] = (f[i][j][k] + f[i - 1][j + 2][k - 2] * C(j + 2) % mod) % mod;
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; i + j <= m; j++) {
            ans = (ans + f[n][i][j]) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}
