#include <iostream>
#include <cstring>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5005,
          M = 10005 << 1;

int f, r, ans;
int idx, head[N], edge[N], next[N];
int cnt, dfn[N], low[N];
int dcc_cnt, siz[N], id[N], in[N];
bool bridge[N];
std::stack<int> st;

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

            if (dfn[u] < low[v]) {
                bridge[i] = bridge[i ^ 1] = true;
            }
        } else if (i != (in_edge ^ 1)) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        dcc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            id[v] = dcc_cnt;
            siz[dcc_cnt]++;
        } while (v != u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(head, 0xff, sizeof(head));

    cin >> f >> r;

    for (int i = 1, u, v; i <= r; i++) {
        cin >> u >> v;

        add(u, v);
        add(v, u);
    }

    tarjan(1, -1);

    for (int i = 0; i < idx; i++) {
        if (bridge[i]) {
            in[id[edge[i]]]++;
        }
    }

    for (int i = 1; i <= dcc_cnt; i++) {
        if (in[i] == 1) ans++;
    }

    cout << (ans + 1) / 2 << endl;

    return 0;
}
