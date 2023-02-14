#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iterator>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005,
          M = 105;

int n, k, m, a[M], b[M], t[M], max, ans;
// 访问过最左端的房子为 l
//      最右端的房子为 r
// 时间已经过了 k 秒
// 目前正在 左(0) / 右(1) 端
int f[M][M][N][2];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0xc0, sizeof(f));

    cin >> n >> k >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> t[i];

        max = std::max(max, t[i]);
    }

    int x = std::distance(a, std::lower_bound(a + 1, a + 1 + m, k)),
        y = std::distance(a, std::upper_bound(a + 1, a + 1 + m, k)) - 1;

    if (a[x] == k) {
        f[x][x][0][0]
            = f[x][x][0][1]
            = (std::abs(a[x] - k) < t[x]) * b[x];
    } else {  // 起始点没有宝可梦
        f[x][x][std::abs(a[x] - k)][0]
            = f[x][x][std::abs(a[x] - k)][1]
            = (std::abs(a[x] - k) < t[x]) * b[x];
        f[y][y][std::abs(a[y] - k)][0]
            = f[y][y][std::abs(a[y] - k)][1]
            = (std::abs(a[y] - k) < t[y]) * b[y];
    }

    for (int len = 2; len <= m; len++) {
        for (int l = 1, r = l + len - 1; r <= m; l++, r++) {
            for (int k = a[r] - a[l]; k <= max; k++) {
                f[l][r][k][0] = std::max({
                    f[l][r][k][0],
                    f[l + 1][r][k - (a[l + 1] - a[l])][0] + (k < t[l]) * b[l],
                    f[l + 1][r][k - (a[r] - a[l])][1] + (k < t[l]) * b[l],
                });

                f[l][r][k][1] = std::max({
                    f[l][r][k][1],
                    f[l][r - 1][k - (a[r] - a[r - 1])][1] + (k < t[r]) * b[r],
                    f[l][r - 1][k - (a[r] - a[l])][0] + (k < t[r]) * b[r],
                });
            }
        }
    }

    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            for (int k = 0; k <= max; k++) {
                ans = std::max({
                    ans,
                    f[l][r][k][0],
                    f[l][r][k][1],
                });
            }
        }
    }

    cout << ans << endl;

    return 0;
}
