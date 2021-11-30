#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, x, y, v, ans, g[5005][5005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> v;
        g[x + 1][y + 1] = v;
    }
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            g[i][j] += g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1];
        }
    }
    for (int i = m; i <= 5001; i++) {
        for (int j = m; j <= 5001; j++) {
            ans = std::max(ans, g[i][j] - g[i - m][j] - g[i][j - m] + g[i - m][j - m]);
        }
    }
    cout << ans << endl;
    return 0;
}
