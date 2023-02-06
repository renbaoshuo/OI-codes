#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005,
          M = 4005;
const int INF = 0x3f3f3f3f;

int n1, n2, n, m, s, t, deg[N << 1];
int idx, head[N << 1], ver[M << 3], edge[M << 3], next[M << 3];
std::pair<int, int> edges[M];
int id[M], dis[N << 1], cur[N << 1];

void add(int u, int v, int w) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = w;
    head[u] = idx++;
}

bool bfs() {
    std::fill(std::begin(dis), std::end(dis), 0);

    std::queue<int> q;

    q.emplace(s);
    dis[s] = 1;
    cur[s] = head[s];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                w = edge[i];

            if (w && !dis[v]) {
                dis[v] = dis[u] + 1;
                cur[v] = head[v];

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

        if (w && dis[v] == dis[u] + 1) {
            int k = dinic(v, std::min(w, limit - flow));

            if (!k) dis[v] = 0;

            edge[i] -= k;
            edge[i ^ 1] += k;
            flow += k;
        }
    }

    return flow;
}

void solve(int x) {
    idx = 0;
    std::fill(std::begin(head), std::end(head), -1);

    s = 0, t = n + 1;

    if (n1 < n2) {
        for (int i = 1; i <= n1; i++) {
            add(s, i, x);
            add(i, s, 0);
        }

        for (int i = n1 + 1; i <= n; i++) {
            add(i, t, x);
            add(t, i, 0);
        }

        for (int i = 1; i <= m; i++) {
            int u = edges[i].first,
                v = edges[i].second;

            id[i] = idx;
            add(u, v, 1);
            add(v, u, 0);
        }
    } else {
        for (int i = 1; i <= n1; i++) {
            add(i, t, x);
            add(t, i, 0);
        }

        for (int i = n1 + 1; i <= n; i++) {
            add(s, i, x);
            add(i, s, 0);
        }

        for (int i = 1; i <= m; i++) {
            int u = edges[i].first,
                v = edges[i].second;

            id[i] = idx;
            add(v, u, 1);
            add(u, v, 0);
        }
    }

    while (bfs()) {
        while (dinic(s, INF)) {}
    }

    for (int i = head[s]; ~i; i = next[i]) {
        edge[i] = INF;
    }

    while (bfs()) {
        while (dinic(s, INF)) {}
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n1 >> n2 >> m;

    n = n1 + n2;

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        v += n1;
        edges[i] = {u, v};
        deg[u]++, deg[v]++;
    }

    int min = *std::min_element(deg + 1, deg + 1 + n);

    for (int k = 0; k <= min; k++) {
        std::vector<int> used_edges;

        solve(k);

        for (int i = 1; i <= m; i++) {
            if (edge[id[i]] == 0) {
                used_edges.emplace_back(i);
            }
        }

        cout << used_edges.size() << ' ';

        for (int x : used_edges) {
            cout << x << ' ';
        }

        cout << endl;
    }

    return 0;
}
