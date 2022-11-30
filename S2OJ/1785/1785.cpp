#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int n, m, k, a[N][N], f[N][N], ans = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            f[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = j + 1; l <= m; l++) {
                f[j][l] += a[i][j] + a[i][l];
            }
        }

        for (int j = 1; j <= m; j++) {
            for (int l = j + 1; l <= m; l++) {
                f[j][l] = std::min({f[j][l], f[j - 1][l] + k, f[j][l - 1] + k});
            }
        }

        for (int j = 1; j <= m; j++) {
            for (int l = m; l > j; l--) {
                f[j][l] = std::min({f[j][l], f[j - 1][l] + k, f[j][l + 1] + k});
            }
        }

        for (int j = m; j; j--) {
            for (int l = j + 1; l <= m; l++) {
                f[j][l] = std::min({f[j][l], f[j + 1][l] + k, f[j][l - 1] + k});
            }
        }

        for (int j = m; j; j--) {
            for (int l = m; l > j; l--) {
                f[j][l] = std::min({f[j][l], f[j + 1][l] + k, f[j][l + 1] + k});
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            ans = std::min(ans, f[i][j] + a[n][i] + a[n][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
