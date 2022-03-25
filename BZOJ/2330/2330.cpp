#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, m, t, a, b;
long long ans;
std::vector<std::pair<int, int>> g[N], g2[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N], siz[N];
std::stack<int> st;
bool vis[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    vis[u] = true;
    for (auto e : g[u]) {
        int v = e.first;
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
            siz[scc_cnt]++;
        } while (v != u);
    }
}

// Longest Path
int dist[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[0].push_back(std::make_pair(i, 1));
    }
    for (int i = 1; i <= m; i++) {
        cin >> t >> a >> b;
        if (t == 1) {
            g[a].push_back(std::make_pair(b, 0));
            g[b].push_back(std::make_pair(a, 0));
        } else if (t == 2) {
            g[a].push_back(std::make_pair(b, 1));
        } else if (t == 3) {
            g[b].push_back(std::make_pair(a, 0));
        } else if (t == 4) {
            g[b].push_back(std::make_pair(a, 1));
        } else {
            g[a].push_back(std::make_pair(b, 0));
        }
    }
    tarjan(0);
    for (int i = 0; i <= n; i++) {
        for (auto e : g[i]) {
            if (id[e.first] != id[i]) {
                g2[id[i]].push_back(std::make_pair(id[e.first], e.second));
            } else if (e.second) {
                cout << -1 << endl;
                exit(0);
            }
        }
    }
    for (int i = scc_cnt; i > 0; i--) {
        for (auto e : g2[i]) {
            int v = e.first,
                w = e.second;
            dist[v] = std::max(dist[v], dist[i] + w);
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        ans += 1ll * dist[i] * siz[i];
    }
    cout << ans << endl;
    return 0;
}
