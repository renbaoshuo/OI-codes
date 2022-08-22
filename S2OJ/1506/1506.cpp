#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, ans;
bool g[N][N], g2[N][N];

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

    for (int i = 1; i <= n; i++) {
        if (!g[u][i]) continue;

        if (!dfn[i]) {
            tarjan(i);
            low[u] = std::min(low[u], low[i]);
        } else if (vis[i]) {
            low[u] = std::min(low[u], dfn[i]);
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

        if (siz[scc_cnt] > 1) ans += siz[scc_cnt];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] && id[i] != id[j]) {
                g2[id[i]][id[j]] = true;
            }
        }
    }

    for (int i = 1; i <= scc_cnt; i++) {
        for (int j = 1; j <= scc_cnt; j++) {
            for (int k = 1; k <= scc_cnt; k++) {
                if (i != j && j != k && g2[i][k] && g2[k][j]) {
                    g2[i][j] = false;
                }
            }
        }
    }

    for (int i = 1; i <= scc_cnt; i++) {
        for (int j = 1; j <= scc_cnt; j++) {
            if (g2[i][j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
