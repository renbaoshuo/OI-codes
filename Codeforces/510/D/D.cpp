#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;
const int INF = 0x3f3f3f3f;

int n, l[N], c[N];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
std::unordered_map<int, bool> vis;
std::unordered_map<int, int> dist;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    q.emplace(0, 0);
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (vis.count(u)) continue;
        vis[u] = true;

        for (int i = 1; i <= n; i++) {
            int v = std::__gcd(u, l[i]);

            if (!dist.count(v)) dist[v] = INF;
            if (dist[v] > dist[u] + c[i]) {
                dist[v] = dist[u] + c[i];
                q.emplace(dist[v], v);
            }
        }
    }

    cout << (dist.count(1) ? dist[1] : -1) << endl;

    return 0;
}
