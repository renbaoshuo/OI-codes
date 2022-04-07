#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 6005;

int n, h[N], f[N][2], root;
std::vector<int> g[N];
bool vis[N];

void dfs(int u) {
    f[u][0] = 0;
    f[u][1] = h[u];

    for (int v : g[u]) {
        dfs(v);
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1, l, k; i < n; i++) {
        cin >> l >> k;
        vis[l] = true;
        g[k].push_back(l);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }

    dfs(root);

    cout << std::max(f[root][0], f[root][1]) << endl;

    return 0;
}
