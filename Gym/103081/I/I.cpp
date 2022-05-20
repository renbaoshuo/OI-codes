#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, m;
std::vector<int> g[N];

// Shortest Path
int dist[N], max;
bool vis[N];

void spfa() {
    memset(dist, 0x3f, sizeof(dist));
    std::queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int v : g[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                max = std::max(max, dist[v]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    spfa();
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f) {
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << (int)ceil(log2(max)) + 1 << endl;
    return 0;
}
