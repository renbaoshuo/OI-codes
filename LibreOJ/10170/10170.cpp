#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, k;
int cnt, r[2005], s[2005];
long long f[15][2005][105], ans;

void dfs(int x, int sum, int len) {
    if (len >= n) {
        r[++cnt] = x;
        s[cnt] = sum;

        return;
    }

    dfs(x, sum, len + 1);
    dfs(x + (1 << len), sum + 1, len + 2);
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    dfs(0, 0, 0);

    for (int i = 1; i <= cnt; i++) f[1][i][s[i]] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            for (int p = 1; p <= cnt; p++) {
                if ((r[j] & r[p]) || ((r[j] << 1) & r[p]) || (r[j] & (r[p] << 1))) continue;

                for (int l = k; l >= s[j]; l--) {
                    f[i][j][l] += f[i - 1][p][l - s[j]];
                }
            }
        }
    }

    for (int i = 1; i <= cnt; i++) ans += f[n][i][k];

    cout << ans << endl;

    return 0;
}
