#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 10005;

int n, m, u, v, a[N];
std::vector<int> g[N], g2[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
int w[N];
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

// Shortest Path
int dist[N];
int spfa(int s) {
    memset(dist, -0x3f, sizeof(dist));
    std::queue<int> q;
    q.push(s);
    dist[s] = 0;
    int res = 0;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (id[i] != id[v]) {
                g2[id[i]].push_back(id[v]);
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
