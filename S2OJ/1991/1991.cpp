#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;

int n, m, a[N];
std::vector<int> g[N], g2[N];
int cnt, dfn[N], low[N];
int scc_cnt, id[N], w[N], dist[N];
bool vis[N];
std::stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    vis[u] = true;
    st.push(u);

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        scc_cnt++;

        int v;
        do {
            v = st.top();
            st.pop();
            vis[v] = false;
            id[v] = scc_cnt;
            w[scc_cnt] += a[v];
        } while (v != u);
    }
}

int spfa(int s) {
    std::fill_n(dist, N, -INF);

    int res = 0;
    std::queue<int> q;

    q.emplace(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        res = std::max(res, dist[u] + w[u]);

        for (int v : g2[u]) {
            if (dist[v] < dist[u] + w[u]) {
                dist[v] = dist[u] + w[u];
                q.push(v);
            }
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].emplace_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (id[i] != id[v]) {
                g2[id[i]].emplace_back(id[v]);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= scc_cnt; i++) {
        ans = std::max(ans, spfa(i));
    }

    cout << ans << endl;

    return 0;
}
