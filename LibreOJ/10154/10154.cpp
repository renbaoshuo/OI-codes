#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int m, n, w[N], f[N][N];
std::vector<int> g[N];

void dfs(int u) {
    // 一门课也不选学分显然为 0
    f[u][0] = 0;

    for (int v : g[u]) {
        dfs(v);

        for (int i = n; ~i; i--) {      // 选课总数
            for (int j = i; ~j; j--) {  // 子树内选课总数
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j]);
            }
        }
    }

    if (u) {
        for (int i = n; i; i--) {
            f[u][i] = f[u][i - 1] + w[u];  // 选这门课也应获得相应学分
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 1, x; i <= m; i++) {
        cin >> x >> w[i];

        g[x].push_back(i);
    }

    dfs(0);

    cout << f[0][n] << endl;

    return 0;
}
