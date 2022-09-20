#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m;
long long ans[N];
std::vector<int> g[N];
int root, cnt, dfn[N], low[N], siz[N];
bool cut[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    siz[u] = 1;

    bool flag = false;
    int sum = 0;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            siz[u] += siz[v];

            if (dfn[u] <= low[v]) {
                if (u != root || flag) {
                    cut[u] = true;
                    sum += siz[v];
                    ans[u] += static_cast<long long>(n - siz[v]) * siz[v];
                } else {
                    flag = true;
                }
            }
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (cut[u]) {
        ans[u] += static_cast<long long>(n - sum - 1) * (sum + 1)
                + n - 1;
    } else {
        ans[u] = 2 * (n - 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
