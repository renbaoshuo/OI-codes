#include <bits/stdc++.h>

using namespace std;

int n, m, l, r, g[35][50005];
long long h, t, p, s[35][50005], ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", g[i] + j);
            s[i][j] = 0ll + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
        }
    }
    cin >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            h = t = p = 1;
            while (p <= m && s[j][p] - s[j][0] - s[i - 1][p] + s[i - 1][0] < l) p++;
            while (p <= m) {
                while (h < p && s[j][p] - s[j][h - 1] - s[i - 1][p] + s[i - 1][h - 1] > r) h++;
                while (t < p && s[j][p] - s[j][t] - s[i - 1][p] + s[i - 1][t] >= l) t++;
                ans += t - h + 1;
                p++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
