#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
char c;
bool w[105][105];

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || !w[x][y]) {
        return;
    }
    w[x][y] = false;
    dfs(x - 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            w[i][j] = c == 'W' ? true : false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (w[i][j]) {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
