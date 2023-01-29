#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;

int n, q, t, cnt = 1, pos = 1, lst,
             a[N], dep[N], fa[N][std::__lg(N) + 1];
std::vector<int> g[N];

void bfs(int s) {
    std::fill_n(dep, N, INF);

    std::queue<int> q;

    q.emplace(s);
    dep[0] = 0;
    dep[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dep[v] > dep[u] + 1) {
                dep[v] = dep[u] + 1;
                q.emplace(v);
                fa[v][0] = u;

                for (int k = 1; k <= std::__lg(n); k++) {
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);

    for (int k = std::__lg(n); k >= 0; k--) {
        if (dep[fa[x][k]] >= dep[y]) {
            x = fa[x][k];
        }
    }

    if (x == y) return x;

    for (int k = std::__lg(n); k >= 0; k--) {
        if (fa[x][k] != fa[y][k]) {
            x = fa[x][k];
            y = fa[y][k];
        }
    }

    return fa[x][0];
}

constexpr int get(int x) {
    return x * (x - 1) / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> t;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i * (i - 1) / 2 + 1; j <= i * (i - 1) / 2 + i; j++) {
            if (a[pos] == j) {
                g[j].emplace_back(++cnt);
                g[j].emplace_back(++cnt);

                pos++;
            } else {
                g[j].emplace_back(++cnt);
            }
        }
    }

    bfs(1);

    while (q--) {
        int x, y;

        cin >> x >> y;

        x = (x - 1 + t * lst) % ((n + 1) * (n + 2) / 2) + 1;
        y = (y - 1 + t * lst) % ((n + 1) * (n + 2) / 2) + 1;

        cout << (lst = lca(x, y)) << endl;
    }

    return 0;
}

