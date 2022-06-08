#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

// f[子树根节点][多少个果子是被大头吃的][是否是大头吃掉了这个果子]
int n, m, k, f[N][N][2], f2[N][2];
std::vector<std::pair<int, int>> g[N];

void dfs(int u, int fa) {
    f[u][0][0] = f[u][1][1] = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;
        dfs(v, u);

        memcpy(f2, f[u], sizeof(f[u]));
        memset(f[u], 0x3f, sizeof(f[u]));

        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                f[u][i][0] = std::min(f[u][i][0], f2[i - j][0] + f[v][j][1]);

                if (m == 2) {
                    f[u][i][0] = std::min(f[u][i][0], f2[i - j][0] + f[v][j][0] + w);
                } else {
                    f[u][i][0] = std::min(f[u][i][0], f2[i - j][0] + f[v][j][0]);
                }

                f[u][i][1] = std::min({f[u][i][1], f2[i - j][1] + f[v][j][1] + w, f2[i - j][1] + f[v][j][0]});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    if (n - k < m - 1) {
        cout << -1 << endl;

        exit(0);
    }

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u].push_back(std::make_pair(v, w));
        g[v].push_back(std::make_pair(u, w));
    }

    memset(f, 0x3f, sizeof(f));

    dfs(1, 0);

    cout << f[1][k][1] << endl;

    return 0;
}
