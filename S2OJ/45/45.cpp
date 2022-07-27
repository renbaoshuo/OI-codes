#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          M = 17;

int n, m, fee[N], cost[N][M], f[N][1 << M], ans = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> fee[i];

        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    memset(f[0], 0x3f, sizeof(f[0]));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1 << m; j++) {
            f[i][j] = f[i - 1][j] + fee[i];
        }

        for (int j = 0; j < 1 << m; j++) {
            for (int k = 0; k < m; k++) {
                if (j & (1 << k)) continue;

                f[i][j | (1 << k)] = std::min(f[i][j | (1 << k)], f[i][j] + cost[i][k]);
            }
        }

        for (int j = 0; j < 1 << m; j++) {
            f[i][j] = std::min(f[i][j], f[i - 1][j]);
        }
    }

    cout << f[n][(1 << m) - 1] << endl;

    return 0;
}
