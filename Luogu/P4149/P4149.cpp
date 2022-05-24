#include <iostream>
#include <limits>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, k, ans = std::numeric_limits<int>::max();
int root, siz[N], max[N];
int cnt;
std::pair<int, int> dist[N];
bool vis[N];
std::vector<std::pair<int, int>> g[N];

void find(int u, int fa, int tot) {
    siz[u] = 1;
    max[u] = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa || vis[v]) continue;

        find(v, u, tot);

        siz[u] += siz[v];
        max[u] = std::max(max[u], siz[v]);
    }

    max[u] = std::max(max[u], tot - siz[u]);

    if (max[u] < max[root]) root = u;
}

void dis(int u, int fa, int w, int l) {
    if (w > k || l > ans) return;

    dist[++cnt] = std::make_pair(w, l);

    for (auto e : g[u]) {
        int _v = e.first,
            _w = e.second;

        if (_v == fa || vis[_v]) continue;

        dis(_v, u, w + _w, l + 1);
    }
}

void calc(int u) {
    std::set<std::pair<int, int>> set;

    set.insert(std::make_pair(0, 0));

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (vis[v]) continue;

        cnt = 0;
        dis(v, u, w, 1);

        for (int i = 1; i <= cnt; i++) {
            auto it = set.lower_bound(std::make_pair(k - dist[i].first, 0));

            if (it != set.end() && it->first + dist[i].first == k) {
                ans = std::min(ans, it->second + dist[i].second);
            }
        }

        for (int i = 1; i <= cnt; i++) set.insert(dist[i]);
    }
}

void solve(int u) {
    vis[u] = true;
    calc(u);

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (vis[v]) continue;

        max[root = 0] = std::numeric_limits<int>::max();
        find(v, 0, siz[v]);
        solve(root);
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;

        g[u + 1].push_back(std::make_pair(v + 1, w));
        g[v + 1].push_back(std::make_pair(u + 1, w));
    }

    max[root = 0] = n;
    find(1, 0, n);
    solve(root);

    cout << (ans == std::numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}
