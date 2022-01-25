#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005,
          M = 200005;

int n, m, min;
long long ans;

// Graph
int idx, head[N], edge[M << 1], ver[M << 1], next[M << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

// Tarjan
int cnt, dfn[N], low[N];
int siz[N];

void tarjan(int u, int in_edge) {
    dfn[u] = low[u] = ++cnt;
    for (int i = head[u]; ~i; i = next[i]) {
        int v = ver[i];
        if (!dfn[v]) {
            tarjan(v, i);
            siz[u] += siz[v] + 1;
            low[u] = std::min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                if (siz[v] % 2 == 0) {
                    min = std::min(min, edge[i]);
                }
            } else {
                min = std::min(min, edge[i]);
            }
        } else if (i != (in_edge ^ 1)) {
            if (dfn[u] > dfn[v]) {
                siz[u]++;
            }
            low[u] = std::min(low[u], dfn[v]);
            min = std::min(min, edge[i]);
        }
    }
}

int main() {
    memset(head, 0xff, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
        ans += w;
    }
    min = INT32_MAX;
    tarjan(1, 0);
    if (m & 1) ans -= min;
    cout << ans << endl;
    return 0;
}
