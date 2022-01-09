#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

const int N = 5005,
          M = 10005;

int f, r, ans;

// Graph
int idx, head[N], edge[M], next[M];

void add(int u, int v) {
    next[idx] = head[u];
    edge[idx] = v;
    head[u] = idx++;
}

// Tarjan
int cnt, dfn[N], low[N];
int dcc_cnt, id[N];
std::stack<int> st;

int deg[N];
bool bridge[N];

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
    if (low[u] == dfn[u]) {
        dcc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            id[v] = dcc_cnt;
        } while (v != u);
    }
}

int main() {
    std::fill(head, head + N, -1);
    cin >> f >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    tarjan(1, -1);
    for (int i = 0; i < idx; i++) {
        if (bridge[i]) {
            deg[id[edge[i]]]++;
        }
    }
    for (int i = 1; i <= dcc_cnt; i++) {
        if (deg[i] == 1) ans++;
    }
    cout << (ans + 1 >> 1) << endl;
    return 0;
}
