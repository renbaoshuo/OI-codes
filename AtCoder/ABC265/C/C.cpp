#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int n, m;
char g[N][N];
bool vis[N][N];

void dfs(int x, int y, int lx, int ly) {
    if (x <= 0 || x > n || y <= 0 || y > m) {
        cout << lx << ' ' << ly << endl;

        exit(0);
    }

    if (vis[x][y]) {
        cout << -1 << endl;

        exit(0);
    }

    vis[x][y] = true;
    switch (g[x][y]) {
        case 'U': {
            dfs(x - 1, y, x, y);
            break;
        }
        case 'D': {
            dfs(x + 1, y, x, y);
            break;
        }
        case 'L': {
            dfs(x, y - 1, x, y);
            break;
        }
        case 'R': {
            dfs(x, y + 1, x, y);
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    dfs(1, 1, 1, 1);

    return 0;
}
