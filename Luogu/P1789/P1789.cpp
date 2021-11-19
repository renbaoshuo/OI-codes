#include <bits/stdc++.h>

using namespace std;
int n, m, k, x, y, o, p, ans = 0;
int dx1[13] = {2, 0, -2, 0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy1[13] = {0, 2, 0, -2, 0, 1, -1, 1, 0, -1, 0, 1, -1};
int dx2[25] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0,
               0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
int dy2[25] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0,
               1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
int main() {
    cin >> n >> m >> k;
    int a[n + 5][n + 5];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        for (int j = 0; j < 13; j++)
            a[x + dx1[j]][y + dy1[j]] = 1;
    }
    for (int i = 1; i <= k; i++) {
        cin >> o >> p;
        for (int j = 0; j < 25; j++)
            a[o + dx2[j]][p + dy2[j]] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 0)
                ans++;
    cout << ans;
    return 0;
}
