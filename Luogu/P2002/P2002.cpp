#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

std::vector<int> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
int din[N];
std::stack<int> st;
bool vis[N];

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
    if (low[u] == dfn[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            id[v] = scc_cnt;
            vis[v] = false;
        } while (v != u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
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
                din[id[v]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
