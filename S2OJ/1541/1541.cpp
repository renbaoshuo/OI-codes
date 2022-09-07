#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305,
          M = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, b[N], fa[N];
long long f[N][M];
std::vector<int> g[N];
bool vis[N];

void dfs(int u) {
    std::fill_n(f[u] + 1, m + 1, 1);

    for (const int& v : g[u]) {
        dfs(v);

        for (int j = 1; j <= m + 1; j++) {
            f[u][j] = (f[u][j] * f[v][j - vis[v]]) % mod;
        }
    }

    if (u) {
        for (int i = 1; i <= m + 1; i++) {
            f[u][i] = (f[u][i] + f[u][i - 1]) % mod;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = true;

        if (b[i] == -1) {
            fa[i] = 0;
        } else {
            fa[i] = b[i];

            for (int j = b[i] + 1; j < i; j++) {
                if (fa[j] <= b[i]) {
                    fa[j] = i;
                    vis[j] = false;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        g[fa[i]].emplace_back(i);
    }

    dfs(0);

    cout << f[0][m + 1] << endl;

    return 0;
}
