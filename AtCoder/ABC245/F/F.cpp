#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, t[N], ans;
std::vector<int> g[N], g2[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N], siz[N];
int dout[N], din[N];
bool vis[N];
std::stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    vis[u] = true;
    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
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

void dfs(int u) {
    for (int v : g2[u]) {
        if (t[v] == -1) dfs(v);
        if (t[v] == 1 || siz[u] > 1) t[u] = 1;
    }
    if (siz[u] > 1) t[u] = 1;
    if (t[u] == -1) t[u] = 0;
}

int main() {
    std::ios::sync_with_stdio(false);

    memset(t, 0xff, sizeof(t));

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
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
            if (id[v] != id[i]) {
                din[id[v]]++;
                g2[id[i]].push_back(id[v]);
            }
        }
    }

    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i]) dfs(i);
    }

    for (int i = 1; i <= scc_cnt; i++) {
        if (t[i] == 1) ans += siz[i];
    }

    cout << ans << endl;
    return 0;
}
