#include <bits/stdc++.h>

using namespace std;

int n, m, t, sx, sy, fx, fy, ans;
int vis[10][10];

void dfs(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n || vis[x][y] == -1 || vis[x][y] == 1) {
        return;
    }
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    vis[x][y] = 1;
    dfs(x - 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y);
    vis[x][y] = 0;
}

int main() {
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        vis[x][y] = -1;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
