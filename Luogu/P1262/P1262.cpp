#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 3005;

int n, p, x, r, u, v, ans, a[N], w[N];
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
            vis[v] = false;
            id[v] = scc_cnt;
            w[scc_cnt] = std::min(w[scc_cnt], a[v]);
        } while (v != u);
    }
}

int main() {
    std::fill(a, a + N, 0x7fff);
    std::fill(w, w + N, 0x7fff);
    cin >> n >> p;
    for (int i = 1; i <= p; i++) {
        cin >> x >> a[x];
    }
    cin >> r;
    for (int i = 1; i <= r; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i] && a[i] != 0x7fff) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            cout << "NO" << endl
                 << i << endl;
            exit(0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : g[i]) {
            if (id[i] != id[v]) {
                din[id[v]]++;
            }
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        if (!din[i]) {
            ans += w[i];
        }
    }
    cout << "YES" << endl
         << ans << endl;
    return 0;
}
