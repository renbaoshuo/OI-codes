#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          M = N * N;
const int INF = 0x3f3f3f3f;

int n, m, s, t, ans;
int idx, head[M], edge[M << 3], ver[M << 3], next[M << 3];
int dist[M], cur[M];

int id(int x, int y) {
    return (x - 1) * m + y;
}

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill(std::begin(dist), std::end(dist), 0);
    std::copy(std::begin(head), std::end(head), std::begin(cur));

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (w && !dist[v]) {
                dist[v] = dist[u] + 1;

                if (v == t) return true;

                q.emplace(v);
            }
        }
    }

    return false;
}

int dinic(int u, int limit) {
    if (u == t) return limit;

    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = next[i]) {
        cur[u] = i;

        int v = ver[i],
            w = edge[i];

        if (dist[v] == dist[u] + 1 && w) {
            int k = dinic(v, std::min(w, limit - flow));

            if (!k) dist[v] = 0;

            edge[i] -= k;
            edge[i ^ 1] += k;
            flow += k;
        }
    }

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> m;

    s = id(1, 1), t = id(n, m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j < m; j++) {
            cin >> x;

            add(id(i, j), id(i, j + 1), x);
            add(id(i, j + 1), id(i, j),x);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1, x; j <= m; j++) {
            cin >> x;

            add(id(i, j), id(i + 1, j), x);
            add(id(i + 1, j), id(i, j), x);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1, x; j < m; j++) {
            cin >> x;

            add(id(i, j), id(i + 1, j + 1), x);
            add(id(i + 1, j + 1), id(i, j), x);
        }
    }

    while (bfs()) {
        while (int flow = dinic(s, INF)) ans += flow;
    }

    cout << ans << endl;

    return 0;
}
