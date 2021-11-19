#include <bits/stdc++.h>

using namespace std;

int n, m;
long long w[1005][1005], f[1005][1005][2];

long long dfs(int x, int y, int from) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return -0x3f3f3f3f;
    }
    if (f[x][y][from] != -0x3f3f3f3f) {
        return f[x][y][from];
    }
    if (from == 0) {
        f[x][y][from] = max({dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)}) + w[x][y];
    } else {
        f[x][y][from] = max({dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)}) + w[x][y];
    }
    return f[x][y][from];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            f[i][j][0] = f[i][j][1] = -0x3f3f3f3f;
        }
    }
    f[1][1][0] = f[1][1][1] = w[1][1];
    cout << dfs(n, m, 1) << endl;
    return 0;
}
