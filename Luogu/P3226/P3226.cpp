#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 20;
const int mod = 1e9 + 1;

int n, g[M][M], w[M], f[2][(1 << M) + 5],
    ans = 1;
bool vis[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int x = 1; x <= n; x++) {
        if (vis[x]) continue;

        // === Build ===

        int height = 0,
            width = 0;

        for (int i = x; i <= n; i *= 2) {
            height++;

            w[height] = 0;

            for (int j = i; j <= n; j *= 3) {
                vis[j] = true;
                w[height]++;
            }

            width = std::max(width, w[height]);
        }

        // === DP ===

        f[0][0] = 1;

        for (int i = 1, k = 1; i <= height; i++, k ^= 1) {
            for (int s = 0; s < 1 << width; s++) {
                f[k][s] = 0;
            }

            for (int s = 0; s < 1 << w[i]; s++) {
                if ((s & (s << 1)) == 0) {
                    for (int t = 0; t < 1 << w[i - 1]; t++) {
                        if ((s & t) == 0 && (t & (t << 1)) == 0) {
                            f[k][s] = (f[k][s] + f[k ^ 1][t]) % mod;
                        }
                    }
                }
            }
        }

        int res = 0;

        for (int s = 0; s < 1 << width; s++) {
            res = (res + f[height & 1][s]) % mod;
        }

        ans = static_cast<long long>(ans) * res % mod;
    }

    cout << ans << endl;

    return 0;
}
