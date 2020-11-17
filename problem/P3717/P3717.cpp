#include <bits/stdc++.h>

using namespace std;

bool vis[105][105];

int main() {
    int n, m, r, x, y, ans = 0;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (sqrt((x - j) * (x - j) + (y - k) * (y - k)) <= r) {
                    vis[j][k] = 1;
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(vis[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
