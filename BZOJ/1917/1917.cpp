#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 50005;

int n, h[N], son[N], ans[N], res;
std::vector<int> g[N];

void dfs1(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;

        dfs1(v, u);

        int x = std::min(h[u], h[v]);

        h[u] -= x, h[v] -= x;
        res += x * 2;

        if (h[v]) son[u] = v;
    }
}

void dfs2(int u, int f) {
    ans[u] = res;

    for (int v : g[u]) {
        if (v == f) continue;

        if (h[u]) {
            h[u]--, res++;

            dfs2(v, u);

            h[u]++, res--;
        } else if (son[v]) {
            h[son[v]]--, res++;

            dfs2(v, u);

            h[son[v]]++, res--;
        } else {
            h[v]++, res--;

            dfs2(v, u);

            h[v]--, res++;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        h[++x]--, h[++y]--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);

        res += 2;
    }

    dfs1(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
