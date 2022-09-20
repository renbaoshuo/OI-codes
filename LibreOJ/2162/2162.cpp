#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 1e6 + 5;

int n, m, d[N], root;
bool vis[N], in_stack[N], edge_used[M];
std::stack<int> st;
std::vector<std::pair<int, int>> g[N];
std::vector<std::vector<int>> ans;

void dfs(int u) {
    vis[u] = true;

    for (auto e : g[u]) {
        int v = e.first,
            id = e.second;

        if (edge_used[id]) continue;
        edge_used[id] = true;

        dfs(v);
    }

    if (in_stack[u]) {
        std::vector<int> res{u};

        while (st.top() != u) {
            res.emplace_back(st.top());
            in_stack[st.top()] = false;
            st.pop();
        }

        res.emplace_back(u);
        ans.emplace_back(res);
    } else {
        st.push(u);
        in_stack[u] = true;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, a, b, s, t; i <= m; i++) {
        cin >> a >> b >> s >> t;

        if (s ^ t) {
            g[a].emplace_back(b, i);
            g[b].emplace_back(a, i);

            d[a]++, d[b]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] % 2 != 0) {
            cout << "NIE" << endl;

            exit(0);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    cout << ans.size() << endl;

    for (auto& item : ans) {
        cout << item.size() - 1 << ' ';

        for (int& x : item) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
