#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, m, w[1005], v[1005], dp[1005][1005];
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}
