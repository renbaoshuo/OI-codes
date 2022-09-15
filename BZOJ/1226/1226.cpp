#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;
const int INF = 0x3f3f3f3f;

int c, n, f[N][1 << 8][20];
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c;

    while (c--) {
        memset(f, 0x3f, sizeof(f));

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }

        f[1][0][7] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 1 << 8; j++) {
                for (int k = -8; k <= 7; k++) {
                    if (f[i][j][k + 8] != INF) {
                        if (j & 1) {  // 当前同学吃了，无需考虑后方
                            f[i + 1][j >> 1][k + 7] = std::min(f[i + 1][j >> 1][k + 7], f[i][j][k + 8]);
                        } else {
                            int t = INF;

                            for (int l = 0; l <= 7; l++) {
                                if (j & 1 << l) continue;
                                if (i + l > t) break;

                                if (i + l <= n) t = std::min(t, i + l + a[i + l].second);
                                else t = std::min(t, i + l);

                                if (i + k) {
                                    int x = i + k <= n ? a[i + k].first : 0,
                                        y = i + l <= n ? a[i + l].first : 0;
                                    f[i][j | 1 << l][l + 8] = std::min(f[i][j | 1 << l][l + 8], f[i][j][k + 8] + (x ^ y));
                                } else {
                                    f[i][j | 1 << l][l + 8] = std::min(f[i][j | 1 << l][l + 8], f[i][j][k + 8]);
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i <= 8; i++) {
            ans = std::min(ans, f[n + 1][0][i]);
        }
        cout << ans << endl;
    }

    return 0;
}
