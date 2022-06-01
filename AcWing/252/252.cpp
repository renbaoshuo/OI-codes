#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005;

int n, k;
bool vis[N];
std::vector<std::pair<int, int>> g[N];

int get_size(int u, int fa) {
    if (vis[u]) return 0;

    int res = 1;

    for (auto e : g[u]) {
        int v = e.first;

        if (v != fa) res += get_size(v, u);
    }

    return res;
}

int get_wc(int u, int fa, int tot, int &wc) {
    if (vis[u]) return 0;

    int siz = 1,
        max = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v == fa) continue;

        int t = get_wc(v, u, tot, wc);

        max = std::max(max, t);
        siz += t;
    }

    max = std::max(max, tot - siz);

    if (max <= tot / 2) wc = u;

    return siz;
}

int p[N], q[N];

void get_dist(int u, int fa, int sum, int &qt) {
    if (vis[u]) return;

    q[qt++] = sum;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        if (v != fa) get_dist(v, u, sum + w, qt);
    }
}

int get(int *a, int x) {
    std::sort(a, a + x);

    int res = 0;

    for (int i = x - 1, j = -1; i >= 0; i--) {
        while (j + 1 < i && a[j + 1] + a[i] <= k) j++;
        j = std::min(j, i - 1);
        res += j + 1;
    }

    return res;
}

int calc(int u) {
    if (vis[u]) return 0;

    int res = 0;

    get_wc(u, -1, get_size(u, -1), u);
    vis[u] = true;

    int pt = 0;

    for (auto e : g[u]) {
        int v = e.first,
            w = e.second;

        int qt = 0;

        get_dist(v, -1, w, qt);
        res -= get(q, qt);

        for (int i = 0; i < qt; i++) {
            if (q[i] <= k) res++;
            p[pt++] = q[i];
        }
    }

    res += get(p, pt);

    for (auto e : g[u]) {
        res += calc(e.first);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> n >> k, n || k) {
        memset(vis, 0x00, sizeof(vis));

        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;

            g[u].push_back(std::make_pair(v, w));
            g[v].push_back(std::make_pair(u, w));
        }

        cout << calc(0) << endl;

        for (int i = 0; i <= n; i++) g[i].clear();
    }

    return 0;
}
