#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, cnt, ans[N];
std::vector<int> g[N];
std::set<int> set;
bool vis[N];

void bfs(int x) {
    std::queue<int> q;

    set.erase(x);
    q.push(x);
    ans[cnt]++;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = true;

        for (auto it = set.begin(); it != set.end();) {
            int v = *it;

            if (*std::lower_bound(g[u].begin(), g[u].end(), v) != v) {
                q.push(v);
                ans[cnt]++;
                set.erase(it++);
            } else {
                it++;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::for_each(g + 1, g + n + 1, [&](auto& v) { std::sort(v.begin(), v.end()); });

    for (int i = 1; i <= n; i++) {
        set.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++;
            bfs(i);
        }
    }

    std::sort(ans + 1, ans + 1 + cnt);

    cout << cnt << endl;

    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << ' ';
    }

    cout << endl;

    return 0;
}
