#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, cnt, s[105], f[105][105][105], ans;
std::pair<int, int> r[105];

void dfs(int x, int sum, int len) {
    if (len >= m) {
        r[++cnt] = std::make_pair(x, sum);
        return;
    }

    dfs(x, sum, len + 1);
    dfs(x + (1 << len), sum + 1, len + 3);
}

bool check(int x, int y) {
    return !(s[x] & y);
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;

            if (c == 'H') {
                s[i] |= 1 << m - j;
            }
        }
    }

    dfs(0, 0, 0);

    memset(f, 0xff, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= cnt; i++) {
        if (check(1, r[i].first)) {
            f[1][i][1] = r[i].second;

            ans = std::max(ans, f[1][i][1]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            if (check(i, r[j].first)) {
                for (int k = 1; k <= cnt; k++) {
                    if (check(i - 1, r[k].first) && !(r[j].first & r[k].first)) {
                        int last = 0;

                        for (int l = 1; l <= cnt; l++) {
                            if (~f[i - 1][k][l] && !(r[j].first & r[l].first) && check(i - 2, r[l].first)) {
                                last = std::max(last, f[i - 1][k][l]);
                            }
                        }

                        f[i][j][k] = std::max(f[i][j][k], last + r[j].second);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= cnt; i++) {
        if (check(n, r[i].first)) {
            for (int j = 1; j <= cnt; j++) {
                if (check(n - 1, r[j].first) && !(r[i].first & r[j].first)) {
                    ans = std::max(ans, f[n][i][j]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
