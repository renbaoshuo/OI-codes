#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5,
          M = 2e6 + 5;

int n, m;
int idx, head[N], ver[M << 1], next[M << 1];
int cnt, dcc_cnt, dfn[N], low[N];
std::stack<int> st;
bool cut[N];
std::vector<int> dcc_points[N];

void add(int u, int v) {
    next[idx] = head[u];
    ver[idx] = v;
    head[u] = idx++;
}

void tarjan(int u, int root) {
    dfn[u] = low[u] = ++cnt;
    st.emplace(u);

    if (u == root && head[u] == -1) {
        dcc_points[++dcc_cnt].emplace_back(u);

        return;
    }

    for (int i = head[u]; ~i; i = next[i]) {
        int v = ver[i];

        if (!dfn[v]) {
            tarjan(v, root);
            low[u] = std::min(low[u], low[v]);

            if (dfn[u] <= low[v]) {
                dcc_cnt++;

                int vv;

                do {
                    vv = st.top();
                    st.pop();
                    dcc_points[dcc_cnt].emplace_back(vv);
                } while (vv != v);

                dcc_points[dcc_cnt].emplace_back(u);
            }
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        if (u == v) continue;

        add(u, v);
        add(v, u);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i, i);
    }

    cout << dcc_cnt << endl;

    for (int i = 1; i <= dcc_cnt; i++) {
        cout << dcc_points[i].size() << ' ';

        std::copy(std::begin(dcc_points[i]), std::end(dcc_points[i]), std::ostream_iterator<int>(cout, " "));

        cout << endl;
    }

    return 0;
}
