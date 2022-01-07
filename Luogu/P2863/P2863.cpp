#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 10005;

int n, m, a, b, ans;
std::vector<int> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N], siz[N];
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
            vis[v] = false;
            id[v] = scc_cnt;
            siz[scc_cnt]++;
        } while (v != u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= scc_cnt; i++) {
        if (siz[i] > 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
