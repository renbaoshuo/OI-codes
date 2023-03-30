#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e4 + 5;

int n, m;
std::vector<int> g[N];
int root, cnt, dfn[N], low[N];
bool cut[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    bool flag = false;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                if (u != root || flag) {
                    cut[u] = true;
                } else {
                    flag = true;
                }
            }
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }

    cout << std::count(cut + 1, cut + n + 1, true) << endl;

    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}
