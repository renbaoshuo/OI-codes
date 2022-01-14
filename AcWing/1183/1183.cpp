#include <array>
#include <iostream>
#include <stack>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 10005;

int ans;
std::array<std::vector<int>, N> g;

// Tarjan
int root;
std::array<int, N> dfn;
int cnt, low[N];
int dcc_cnt, id[N];
std::stack<int> st;

void tarjan(int);

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        ans = dcc_cnt = cnt = 0;
        dfn.fill(0);
        g.fill({});
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a + 1].push_back(b + 1);
            g[b + 1].push_back(a + 1);
        }
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                root = i;
                dcc_cnt++;
                tarjan(i);
            }
        }
        cout << ans + dcc_cnt - 1 << endl;
    }
    return 0;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    int size = 0;
    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) size++;
        } else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (u != root) size++;
    ans = std::max(ans, size);
}
