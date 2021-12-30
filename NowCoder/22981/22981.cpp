#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 105;

int n, x, ans1, ans2;
std::vector<int> g[N];
int din[N], dout[N];  // 图的入度、出度

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
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
    if (dfn[u] == low[u]) {
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while (cin >> x, x) {
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (id[i] != id[v]) {
                dout[id[i]]++;
                din[id[v]]++;
            }
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i]) ans1++;
        if (!dout[i]) ans2++;
    }
    cout << ans1 << endl
         << (scc_cnt == 1 ? 0 : std::max(ans1, ans2)) << endl;
    return 0;
}
