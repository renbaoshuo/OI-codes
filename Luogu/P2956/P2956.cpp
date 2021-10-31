#include <bits/stdc++.h>

using namespace std;

bool vis[250][250];

int main() {
    int x, y, p, x1, x2, y1, y2, ans = 0;
    cin >> x >> y >> p;
    for (int i = 0; i < p; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                vis[j][k] = true;
            }
        }
    }
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (vis[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
