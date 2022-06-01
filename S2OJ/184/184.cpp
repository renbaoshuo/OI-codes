#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
#define endl '\n'

int n, x, dist[105];
std::vector<std::pair<int, int>> g[105];
bool vis[105];

void spfa(int s) {
    memset(dist, 0x3f, sizeof(dist));
    std::queue<int> q;
    q.push(s);
    vis[s] = true;
    dist[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto e : g[u]) {
            int v = e.first,
                w = e.second;
            if (dist[v] > std::max(1, (dist[u] + w + 1) / 2)) {
                dist[v] = std::max(1, (dist[u] + w + 1) / 2);
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x) g[j].push_back(std::make_pair(i, -x));
        }
    }
    spfa(n);
    cout << dist[1] << endl;
    return 0;
}
