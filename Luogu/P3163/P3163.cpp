#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55,
          M = (N * N) << 1;
const int INF = 0x3f3f3f3f;

int n, s, t, a1, a2, an, b1, b2, bn;
int idx, head[N], head2[N], ver[M << 1], edge[M << 1], edge2[M << 1], next[M << 1];
int dis[N], cur[N];

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

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> a1 >> a2 >> an >> b1 >> b2 >> bn) {
        a1++, a2++, b1++, b2++;
        s = 0, t = n + 1;

        idx = 0;
        std::fill(std::begin(head), std::end(head), -1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                char c;

                cin >> c;

                if (c == 'O') {
                    add(i, j, 2);
                    add(j, i, 0);
                } else if (c == 'N') {
                    add(i, j, INF);
                    add(j, i, 0);
                }
            }
        }

        bool ans = true;

        for (int _ = 0; _ < 2; _++) {
            // Backup
            int idx2 = idx;
            std::copy(std::begin(head), std::end(head), std::begin(head2));
            std::copy(std::begin(edge), std::end(edge), std::begin(edge2));

            add(s, a1, an * 2);
            add(a1, s, 0);

            add(s, b1, bn * 2);
            add(b1, s, 0);

            add(a2, t, an * 2);
            add(t, a2, 0);

            add(b2, t, bn * 2);
            add(t, b2, 0);

            int res = 0;

            while (bfs()) {
                while (int flow = dinic(s, INF)) res += flow;
            }

            ans &= res == (an + bn) * 2;

            std::swap(b1, b2);

            // Restore backup
            idx = idx2;
            std::copy(std::begin(head2), std::end(head2), std::begin(head));
            std::copy(std::begin(edge2), std::end(edge2), std::begin(edge));
        }

        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}
