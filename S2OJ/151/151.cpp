#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 105;
const int mod = 1e9 + 7;
const int p[]{2, 3, 5, 7};

int cnt, f[M][M][(1 << 4) + 5];
std::vector<std::pair<int, int>> v[M], a[M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= 100; i++) {
        int x = i, s = 0;

        for (int j = 0; j < 4; j++) {
            while (x && x % p[j] == 0) {
                x /= p[j];
                s |= 1 << j;
            }
        }

        v[x].emplace_back(i, s);
    }

    for (auto o : v[1]) {
        a[++cnt].emplace_back(o);
    }

    for (int i = 2; i <= 100; i++) {
        if (v[i].empty()) continue;

        cnt++;

        for (auto o : v[i]) {
            a[cnt].emplace_back(o);
        }
    }

    int t;

    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        memset(f, 0x00, sizeof(f));

        f[0][0][0] = 1;

        for (int i = 1; i <= cnt; i++) {
            for (int j = 0; j <= i; j++) {
                for (int s = 0; s < 1 << 4; s++) {
                    if (f[i - 1][j][s]) {
                        f[i][j][s] = (static_cast<long long>(f[i][j][s]) + f[i - 1][j][s]) % mod;

                        for (auto o : a[i]) {
                            if (o.first > m) break;

                            if (!(s & o.second)) {
                                f[i][j + 1][s | o.second]
                                    = (static_cast<long long>(f[i][j + 1][s | o.second])
                                       + static_cast<long long>(f[i - 1][j][s]) * (n - j))
                                    % mod;
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int j = 0; j <= cnt; j++) {
            for (int s = 0; s < 1 << 4; s++) {
                ans = (static_cast<long long>(ans) + f[cnt][j][s]) % mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
