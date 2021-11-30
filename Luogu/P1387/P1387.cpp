#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, ans;
bool g[105][105];

bool check(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (!g[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= std::min(n, m); k++) {
                if (i + k > n || j + k > m) break;
                if (check(i, j, i + k - 1, j + k - 1)) {
                    ans = std::max(ans, k);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
