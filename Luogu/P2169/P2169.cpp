#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 200005;

// Graphs
int w[N];
std::vector<std::pair<int, int>> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
std::stack<int> st;
bool vis[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    vis[u] = true;
    for (auto v : g[u]) {
        if (!dfn[v.first]) {
            tarjan(v.first);
            low[u] = std::min(low[u], low[v.first]);
        } else if (vis[v.first]) {
            low[u] = std::min(low[u], dfn[v.first]);
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
        } while (v != u);
    }
}

// Shortest Path
int dist[N];

void spfa() {
    std::fill(dist, dist + N, 0x3f3f3f3f);
    std::fill(vis, vis + N, false);
    std::queue<int> q;
    q.push(1);
    dist[1] = 0;
    vis[1] = true;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto v : g[u]) {
            int w = v.second;
            if (id[u] == id[v.first]) w = 0;
            if (dist[v.first] > dist[u] + w) {
                dist[v.first] = dist[u] + w;
                if (!vis[v.first]) {
                    q.push(v.first);
                    vis[v.first] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(std::make_pair(v, w));
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    spfa();
    cout << dist[n] << endl;
    return 0;
}
