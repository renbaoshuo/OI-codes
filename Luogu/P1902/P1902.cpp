#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

const int nxt[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int n, m, l, r, ans, g[1005][1005];
bool vis[1005][1005];

bool bfs(int x, int y, int k) {
    memset(vis, 0x00, sizeof(vis));
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));
    vis[x][y] = true;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.first + nxt[i][0];
            int ny = t.second + nxt[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny]) continue;
            if (g[nx][ny] > k) continue;
            vis[nx][ny] = true;
            if (nx == n) return true;
            q.push(std::make_pair(nx, ny));
        }
    }
    return false;
}

int main() {
    l = std::numeric_limits<int>::max();
    r = std::numeric_limits<int>::min();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            l = std::min(l, g[i][j]);
            r = std::max(r, g[i][j]);
        }
    }
    while (l <= r) {
        int mid = l + r >> 1;
        if (bfs(1, 1, mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
