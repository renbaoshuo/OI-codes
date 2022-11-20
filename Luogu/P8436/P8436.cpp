#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5,
          M = 2e6 + 5;

int n, m, ans;
int idx, head[N], edge[M << 1], next[M << 1];
int cnt, dcc_cnt, dfn[N], low[N];
std::stack<int> st;
std::vector<int> nodes[N];

void add(int u, int v) {
    next[idx] = head[u];
    edge[idx] = v;
    head[u] = idx++;
}

void tarjan(int u, int in_edge) {
    dfn[u] = low[u] = ++cnt;
    st.push(u);

    for (int i = head[u]; ~i; i = next[i]) {
        int v = edge[i];

        if (!dfn[v]) {
            tarjan(v, i);
            low[u] = std::min(low[u], low[v]);
        } else if (i != (in_edge ^ 1)) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        dcc_cnt++;

        int v;
        do {
            v = st.top();
            st.pop();
            nodes[dcc_cnt].push_back(v);
        } while (v != u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill_n(head, N, -1);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }

    cout << dcc_cnt << endl;

    for (int i = 1; i <= dcc_cnt; i++) {
        cout << nodes[i].size() << ' ';

        for (int x : nodes[i]) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
