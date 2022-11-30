#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55,
          M = (N << 1) * (N << 1);
const int INF = 0x3f3f3f3f;

int n, cnt, s, t, cost;
int idx, head[N << 1], ver[M << 1], next[M << 1];
std::pair<int, int> edge[M << 1];
std::unordered_map<int, int> cnt_x, cnt_y, id_x, id_y;
std::set<std::pair<int, int>> set;
int dist[N << 1];
bool vis[N << 1];

void add(int u, int v, int flow, int cost) {
    next[idx] = head[u];
    ver[idx] = v;
    edge[idx] = std::make_pair(flow, cost);
    head[u] = idx++;
}

bool spfa() {
    std::fill(std::begin(vis), std::end(vis), false);
    std::fill(std::begin(dist), std::end(dist), INF);

    std::queue<int> q;

    q.emplace(s);
    dist[s] = 0;
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (int i = head[u]; ~i; i = next[i]) {
            int v = ver[i],
                flow = edge[i].first,
                cost = edge[i].second;

            if (flow && dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;

                if (!vis[v]) {
                    q.emplace(v);
                    vis[v] = true;
                }
            }
        }
    }

    return dist[t] != INF;
}

int dinic(int u, int limit) {
    if (u == t) return limit;

    int flow = 0;

    vis[u] = true;

    for (int i = head[u]; ~i && flow < limit; i = next[i]) {
        int v = ver[i],
            f = edge[i].first,
            w = edge[i].second;

        if (dist[v] == dist[u] + w && f && !vis[v]) {
            int k = dinic(v, std::min(f, limit - flow));

            if (!k) dist[v] = INF;

            edge[i].first -= k;
            edge[i ^ 1].first += k;
            flow += k;
            cost += k * w;
        }
    }

    vis[u] = false;

    return flow;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n;

    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;

        cnt_x[x]++, cnt_y[y]++;
        set.emplace(x, y);

        if (!id_x.count(x)) id_x[x] = ++cnt;
        if (!id_y.count(y)) id_y[y] = ++cnt;
    }

    s = 0, t = cnt + 1;

    for (auto o : id_x) {
        add(s, o.second, cnt_x[o.first], 0);
        add(o.second, s, 0, 0);
    }

    for (auto o : id_y) {
        add(o.second, t, cnt_y[o.first], 0);
        add(t, o.second, 0, 0);
    }

    for (auto a : id_x) {
        for (auto b : id_y) {
            if (set.count(std::make_pair(a.first, b.first))) {
                add(a.second, b.second, 1, 1);
                add(b.second, a.second, 0, -1);
            } else {
                add(a.second, b.second, 1, 0);
                add(b.second, a.second, 0, 0);
            }
        }
    }

    while (spfa()) dinic(s, INF);

    cout << cost << endl;

    return 0;
}
