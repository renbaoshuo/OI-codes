#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m;
std::vector<int> g[N];
int color[N];

bool dfs(int u, int c) {
    color[u] = c;

    for (int v : g[u]) {
        if (~color[v]) {                      // 如果已经染色
            if (color[v] == c) return false;  // 同色，矛盾
        } else {
            if (!dfs(v, c ^ 1)) return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(color), std::end(color), -1);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 图可能不连通
    for (int i = 1; i <= n; i++) {
        if (!~color[i]) {  // 如果没有染色
            if (!dfs(i, 0)) {
                cout << "No" << endl;

                exit(0);
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}
