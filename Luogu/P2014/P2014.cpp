#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int n, m, s[N], f[N][N];
std::vector<int> g[N];

void dfs(int u) {
    f[u][0] = 0;

    for (int v : g[u]) {
        dfs(v);

        for (int i = m; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
            }
        }
    }

    if (u) {
        for (int i = m; i; i--) {
            f[u][i] = f[u][i - 1] + s[u];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(f, 0xcf, sizeof(f));

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x >> s[i];

        g[x].push_back(i);
    }

    dfs(0);

    cout << f[0][m] << endl;

    return 0;
}
