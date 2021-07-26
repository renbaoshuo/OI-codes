#include <bits/stdc++.h>

using namespace std;

int n, m, ans, dp[505][505];

struct node {
    int x, y;

    node() {}
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
    node operator-(node B) {
        return node(x - B.x, y - B.y);
    }
} hou[505], fri[505];

inline int det(node A, node B) {
    return A.x * B.y - A.y * B.x;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> hou[i].x >> hou[i].y;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> fri[i].x >> fri[i].y;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = -1;
                if (i == j) continue;
                bool ok = true;
                for (int k = 1; k <= n; k++)
                    if (det(hou[k] - fri[i], fri[j] - fri[i]) > 0) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    dp[i][j] = 1;
                }
            }
        }
        for (int k = 1; k <= m; k++) {
            for (int i = 1; i <= m; i++) {
                if (dp[i][k] == -1) continue;
                for (int j = 1; j <= m; j++) {
                    if (dp[k][j] == -1) continue;
                    dp[i][j] = dp[i][j] == -1 ? dp[i][k] + dp[k][j] : min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        ans = -1;
        for (int i = 1; i <= m; i++) {
            if (dp[i][i] == -1) continue;
            ans = ans == -1 ? dp[i][i] : min(ans, dp[i][i]);
        }
        if (ans == -1) {
            cout << "ToT" << endl;
        } else {
            cout << m - ans << endl;
        }
    }
    return 0;
}
