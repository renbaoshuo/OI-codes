#include <iostream>
#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, s, t, f[N], ans;
std::tuple<int, int, int> points[N];
int idx, head[N << 1], ver[N << 2], edge[N << 2], next[N << 2];
int cur[N << 1], dist[N << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill_n(dist, N << 1, 0);

    std::queue<int> q;

    q.push(s);
    dist[s] = 1;
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (w && !dist[v]) {
                dist[v] = dist[u] + 1;
                cur[v] = head[v];
                if (v == t) return true;
                q.push(v);
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

            if (!k) {
                dist[v] = 0;
            } else {
                flow += k;
                edge[i] -= k;
                edge[i ^ 1] += k;
            }
        }
    }

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill_n(head, N << 1, -1);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> std::get<0>(points[i]) >> std::get<1>(points[i]) >> std::get<2>(points[i]);
    }

    std::sort(points + 1, points + 1 + n);

    for (int i = 1; i <= n; i++) {
        f[i] = 1;

        for (int j = 1; j < i; j++) {
            int x1, y1, z1,
                x2, y2, z2;

            std::tie(x1, y1, z1) = points[i];
            std::tie(x2, y2, z2) = points[j];

            if (x2 < x1 && y2 < y1 && z2 < z1) {
                f[i] = std::max(f[i], f[j] + 1);

                add(j, i + n, 1);
                add(i + n, j, 0);
            }
        }

        ans = std::max(ans, f[i]);
    }

    s = n * 2 + 1, t = s + 1;
    for (int i = 1; i <= n; i++) {
        add(s, i, 1);
        add(i, s, 0);

        add(i + n, t, 1);
        add(t, i + n, 0);
    }

    int res = 0, flow;
    while (bfs()) {
        while (flow = dinic(s, std::numeric_limits<int>::max())) res += flow;
    }

    cout << ans << endl
         << n - res << endl;

    return 0;
}
