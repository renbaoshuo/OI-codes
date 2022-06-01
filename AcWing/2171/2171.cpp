#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          M = 10005;

int n, m, s, t, ans;

// Graph
int idx, head[N], ver[M << 1], edge[M << 1], next[M << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

// Edmonds-Karp
int d[N], pre[N];
bool vis[N];

bool bfs() {
    memset(vis, 0x00, sizeof(vis));
    std::queue<int> q;
    q.push(s);
    vis[s] = true;
    d[s] = std::numeric_limits<int>::max();
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; ~i; i = next[i]) {
            if (edge[i]) {
                int y = ver[i];
                if (vis[y]) continue;
                d[y] = std::min(d[x], edge[i]);
                pre[y] = i;
                q.push(y);
                vis[y] = true;
                if (y == t) return true;
            }
        }
    }
    return false;
}

void update() {
    int x = t;
    while (x != s) {
        int i = pre[x];
        edge[i] -= d[t];
        edge[i ^ 1] += d[t];
        x = ver[i ^ 1];
    }
    ans += d[t];
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(head, 0xff, sizeof(head));
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }
    while (bfs()) update();
    cout << ans << endl;
    return 0;
}
