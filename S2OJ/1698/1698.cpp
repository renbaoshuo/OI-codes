#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int t, n, m, q, cnt, block[N], color[N];
std::vector<int> g[N];
bool flag[N];

void dfs(int u, int f) {
    block[u] = cnt;

    for (int v : g[u]) {
        if (color[v] != -1 && color[u] == color[v]) {
            flag[cnt] = true;
        } else if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            dfs(v, u);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::fill_n(color, N, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            cnt++;
            color[i] = 0;
            dfs(i, 0);
        }
    }

    cin >> q;

    while (q--) {
        int s, t;

        cin >> s >> t;

        if (s == t) {
            cout << 0 << endl;
        } else if (block[s] != block[t]) {
            cout << -1 << endl;
        } else if (flag[block[s]] || color[s] != color[t]) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
