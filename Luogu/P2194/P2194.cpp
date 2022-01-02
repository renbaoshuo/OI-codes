#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;
const int mod = 1e9 + 7;

int n, m, u, v, a[N], ans1, ans2;
std::vector<int> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N];
std::stack<int> st;
bool vis[N];
int w[N], s[N];

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
            if (w[scc_cnt] > a[v]) {
                w[scc_cnt] = a[v];
                s[scc_cnt] = 1;
            } else if (w[scc_cnt] == a[v]) {
                s[scc_cnt]++;
            }
        } while (v != u);
    }
}

int main() {
    ans2 = 1;
    std::fill(w, w + N, 0x3f3f3f3f);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        ans1 += w[i];
        ans2 = ans2 * s[i] % mod;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
