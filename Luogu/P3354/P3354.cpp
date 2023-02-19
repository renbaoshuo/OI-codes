#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, k, w[N], v[N], d[N], dis[N];
int f[N][2][N][N];
std::vector<int> g[N], st;

void dfs(int u) {
    st.emplace_back(u);

    for (int v : g[u]) {
        dis[v] = dis[u] + d[v];

        dfs(v);

        for (int t : st) {
            for (int i = k; i >= 0; i--) {
                f[u][0][t][i] += f[v][0][t][0];
                f[u][1][t][i] += f[v][0][u][0];

                for (int j = 1; j <= i; j++) {
                    f[u][0][t][i] = std::min(f[u][0][t][i], f[v][0][t][j] + f[u][0][t][i - j]);
                    f[u][1][t][i] = std::min(f[u][1][t][i], f[v][0][u][j] + f[u][1][t][i - j]);
                }
            }
        }
    }

    for (int t : st) {
        for (int i = k; i; i--) {
            f[u][0][t][i] = std::min(f[u][0][t][i] + w[u] * (dis[u] - dis[t]), f[u][1][t][i - 1]);
        }

        f[u][0][t][0] += w[u] * (dis[u] - dis[t]);
    }

    st.pop_back();
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i] >> d[i];

        g[v[i]].emplace_back(i);
    }

    dfs(0);

    cout << f[0][0][0][k] << endl;

    return 0;
}
