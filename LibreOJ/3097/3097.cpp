#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          M = N * N;
const int INF = 0x3f3f3f3f;

int n, w, a[N], s, t, tot, pos1[N], pos2[N];
long long cost;
int idx, head[N << 4], ver[M << 5], next[M << 5];
std::pair<int, int> edge[M << 5];
int dist[N << 4];
bool vis[N << 4];

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

void solve(int l, int r) {
    if (l == r) return;

    int mid = (l + r) >> 1;

    solve(l, mid);
    solve(mid + 1, r);

    std::vector<int> nums;

    for (int i = l; i <= r; i++) {
        nums.emplace_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size() - 1; i++) {
        add(tot + 1 + i, tot + 1 + i + 1, INF, nums[i + 1] - nums[i]);
        add(tot + 1 + i + 1, tot + 1 + i, 0, -(nums[i + 1] - nums[i]));

        add(tot + 1 + i + 1, tot + 1 + i, INF, nums[i + 1] - nums[i]);
        add(tot + 1 + i, tot + 1 + i + 1, 0, -(nums[i + 1] - nums[i]));
    }

    for (int i = l; i <= r; i++) {
        int pos = std::lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();

        if (i <= mid) {
            add(tot + 1 + pos, pos2[i], 1, 0);
            add(pos2[i], tot + 1 + pos, 0, 0);
        } else {
            add(pos1[i], tot + 1 + pos, 1, 0);
            add(tot + 1 + pos, pos1[i], 0, 0);
        }
    }

    tot += nums.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(head), std::end(head), -1);

    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    s = 0, t = ++tot;

    for (int i = 1; i <= n; i++) {
        pos1[i] = ++tot;
        pos2[i] = ++tot;

        // S -> i_1
        add(s, pos1[i], 1, 0);
        add(pos1[i], s, 0, 0);

        // i_1 -> T
        add(pos1[i], t, 1, w);
        add(t, pos1[i], 0, -w);

        // i_2 -> T
        add(pos2[i], t, 1, 0);
        add(t, pos2[i], 0, 0);
    }

    solve(1, n);

    while (spfa()) {
        while (dinic(s, INF)) {}
    }

    cout << cost << endl;

    return 0;
}
