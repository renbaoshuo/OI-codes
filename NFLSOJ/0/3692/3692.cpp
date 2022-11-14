#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("graph.in");
std::ofstream cout("graph.out");
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, d[N], ans;
std::vector<int> g[N];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
bool vis[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x, y; i <= m; ++i) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
        d[x]++, d[y]++;
    }

    ans = *std::min_element(d + 1, d + 1 + n);

    for (int i = 1; i <= n; i++) {
        q.emplace(d[i], i);
    }

    while (!q.empty()) {
        auto o = q.top();
        q.pop();

        while (!q.empty() && o.first != d[o.second]) {
            o = q.top();
            q.pop();
        }

        if (!q.empty()) {
            vis[o.second] = true;
            d[o.second] = 0;

            ans = std::max(ans, o.first);

            for (int v : g[o.second]) {
                if (!vis[v]) {
                    d[v]--;
                    q.emplace(d[v], v);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
