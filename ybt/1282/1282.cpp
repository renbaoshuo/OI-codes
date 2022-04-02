#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, g[N][N], sum[N], f[N], ans = -0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                sum[k] = 0;
                for (int l = i; l <= j; l++) {
                    sum[k] += g[k][l];
                }
            }

            f[0] = -0x3f3f3f3f;
            for (int k = 1; k <= n; k++) {
                f[k] = std::max(f[k - 1] + sum[k], sum[k]);
                ans = std::max(ans, f[k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
