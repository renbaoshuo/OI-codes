#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const long long INF = 0x3f3f3f3f'3f3f3f3f;

int n;
long long dist[N], dep[N], pre[N], suf[N], a[N], b[N], c[N], d[N], ans1, ans2;
std::vector<std::pair<int, int>> g[N], circle;
bool vis[N], on_circle[N];

bool dfs(int u, int f) {
    if (vis[u]) return true;

    vis[u] = true;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == f) continue;

        if (dfs(v, u)) {
            circle.emplace_back(v, w);
            on_circle[v] = true;

            return true;
        }
    }

    return false;
}

std::pair<int, long long> bfs(int s) {
    int res = s;
    std::queue<int> q;
    std::unordered_set<int> set;

    q.emplace(s);
    set.emplace(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;

            if (!vis[v] && !on_circle[v]) {
                dist[v] = dist[u] + w;

                if (dist[v] > dist[res]) res = v;

                q.emplace(v);
                set.emplace(v);
                vis[v] = true;
            }
        }
    }

    long long dist_res = dist[res];

    for (int u : set) {
        vis[u] = false;
        dist[u] = INF;
    }

    return {res, dist_res};
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v, w; i <= n; i++) {
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1, 0);
    std::reverse(circle.begin(), circle.end());
    std::fill(std::begin(vis), std::end(vis), false);
    std::fill(std::begin(dist), std::end(dist), INF);

    for (int i = 1; i <= circle.size(); i++) {
        int u = circle[i - 1].first;

        on_circle[u] = false;

        auto o = bfs(u);

        dep[i] = o.second;
        ans1 = std::max(ans1, bfs(o.first).second);

        on_circle[u] = true;
    }

    for (int i = 2; i <= circle.size(); i++) {
        pre[i] = pre[i - 1] + circle[i - 1].second;
    }

    for (int i = circle.size() - 1; i; i--) {
        suf[i] = suf[i + 1] + circle[i].second;
    }

    for (int i = 1; i <= circle.size(); i++) {
        a[i] = std::max(a[i - 1], dep[i] + pre[i]);
    }

    for (int i = circle.size(); i; i--) {
        b[i] = std::max(b[i + 1], dep[i] + suf[i]);
    }

    long long max = 0;
    for (int i = 1; i <= circle.size(); i++) {
        c[i] = std::max(c[i - 1], max + dep[i] + pre[i]);
        max = std::max(max, dep[i] - pre[i]);
    }

    max = 0;
    for (int i = circle.size(); i; i--) {
        d[i] = std::max(d[i + 1], max + dep[i] + suf[i]);
        max = std::max(max, dep[i] - suf[i]);
    }

    ans2 = INF;
    for (int i = 1; i < circle.size(); i++) {
        ans2 = std::min(ans2, std::max({a[i] + b[i + 1] + circle[0].second, c[i], d[i + 1]}));
    }

    cout << std::fixed << std::setprecision(1) << static_cast<double>(std::max(ans1, ans2)) / 2 << endl;

    return 0;
}
