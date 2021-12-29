#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 10005;

int n, m, a, b;
std::vector<int> g[N];

// Tarjan
int cnt, dfn[N], low[N];
int scc_cnt, id[N], siz[N];
int dout[N];
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

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
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
            }
        }
    }
    int z = 0, sum = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (!dout[i]) {
            z++;
            sum += siz[i];
            if (z > 1) {
                sum = 0;
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
