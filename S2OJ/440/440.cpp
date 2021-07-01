#include <bits/stdc++.h>

using namespace std;

int n, l, k, root, dp[6005][2], p[6005];

void dfs(int x) {
    for (int i = 1; i <= n; i++) {
        if (p[i] == x) {
            dfs(i);
            dp[x][0] += max(dp[i][0], dp[i][1]);
            dp[x][1] += dp[i][0];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][1];
    }
    while (cin >> l >> k && (l != 0 && k != 0)) {
        p[l] = k;
    }
    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            root = i;
        }
    }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}
