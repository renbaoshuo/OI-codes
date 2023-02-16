#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, k, l, a[N], b[N];
std::vector<int> g[N];
int dfn[N], low[N];
bool bridge[N];
std::vector<std::pair<int, int>> ans;

void tarjan(int u, int f) {
    static int cnt = 0;

    dfn[u] = low[u] = ++cnt;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v, u);

            low[u] = std::min(low[u], low[v]);

            if (dfn[u] < low[v]) {
                if (a[v] == 0 || b[v] == 0 || a[v] == k || b[v] == l) {
                    ans.emplace_back(u, v);
                }
            }

            a[u] += a[v];
            b[u] += b[v];
        } else if (v != f) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> l;

    for (int i = 1, x; i <= k; i++) {
        cin >> x;

        a[x] = 1;
    }

    for (int i = 1, x; i <= l; i++) {
        cin >> x;

        b[x] = 1;
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    tarjan(1, 1);

    cout << ans.size() << endl;

    for (auto e : ans) {
        cout << e.first << ' ' << e.second << endl;
    }

    return 0;
}
