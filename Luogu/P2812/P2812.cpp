#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, x, ans1, ans2;
std::vector<int> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
std::stack<int> st;
bool vis[N];
int din[N], dout[N];

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
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (id[i] != id[v]) {
                din[id[v]]++;
                dout[id[i]]++;
            }
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        ans1 += !din[i];
        ans2 += !dout[i];
    }
    cout << ans1 << endl
         << (scc_cnt == 1 ? 0 : std::max(ans1, ans2)) << endl;
    return 0;
}
