#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1},
          dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n, m, t, ans;
std::pair<int, int> match[N][N];
bool disabled[N][N], vis[N][N];

bool dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i],
            yy = y + dy[i];

        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (disabled[xx][yy] || vis[xx][yy]) continue;

        vis[xx][yy] = true;

        auto t = match[xx][yy];

        if (!t.first || dfs(t.first, t.second)) {
            match[xx][yy] = std::make_pair(x, y);
            return true;
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 1; i <= t; i++) {
        int x, y;

        cin >> x >> y;

        disabled[x][y] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (disabled[i][j] || (i + j) % 2) continue;

            memset(vis, 0x00, sizeof(vis));
            if (dfs(i, j)) ans++;
        }
    }

    cout << n * m - t - ans << endl;

    return 0;
}
