#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, vis[405][405];

const int dx[] = {0, -2, -2, -1, -1, +1, +1, +2, +2};
const int dy[] = {0, -1, +1, -2, +2, -2, +2, -1, +1};

inline void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for (int i = 1; i <= 8; i++) {
            int u = xx + dx[i];
            int v = yy + dy[i];
            if (u < 1 || u > n || v < 1 || v > m || vis[u][v] != -1) continue;
            q.push(make_pair(u, v));
            vis[u][v] = vis[xx][yy] + 1;
        }
    }
}

int main() {
    memset(vis, 0xff, sizeof(vis));
    scanf("%d%d%d%d", &n, &m, &x, &y);
    vis[x][y] = 0;
    bfs(x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", vis[i][j]);
        }
        printf("\n");
    }
    return 0;
}
