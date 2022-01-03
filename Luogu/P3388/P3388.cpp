#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 20005;

int n, m, x, y;
std::vector<int> ans, g[N];

// Tarjan
int cnt, dfn[N], low[N];
int root;
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
