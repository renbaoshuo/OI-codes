#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], c[N], siz[N], max[N],
    _cnt[N << 1], *cnt(_cnt + N), pos[N], sum[N], root, ans;
std::vector<int> g[N];
bool vis[N];

void get_root(int u, int f, int s) {
    siz[u] = 1;
    max[u] = 0;

    for (auto v : g[u]) {
        if (v == f || vis[v]) continue;

        get_root(v, u, s);

        siz[u] += siz[v];
        max[u] = std::max(max[u], siz[v]);
    }

    max[u] = std::max(max[u], s - siz[u]);

    if (!root || max[u] < max[root]) {
        root = u;
    }
}

void add(int u, int f, int d) {
    cnt[d]++;

    for (int v : g[u]) {
        if (v == f || vis[v]) continue;

        add(v, u, d + c[v]);
    }
}

void del(int u, int f, int d) {
    cnt[d]--;

    for (int v : g[u]) {
        if (v == f || vis[v]) continue;

        del(v, u, d + c[v]);
    }
}

void calc(int u, int f, int d) {
    sum[pos[u]] += cnt[-d];

    for (int v : g[u]) {
        if (v == f || vis[v]) continue;

        calc(v, u, d + c[v]);
    }
}

void solve(int u) {
    vis[u] = true;
    cnt[0]++;

    for (int v : g[u]) {
        if (vis[v]) continue;

        calc(v, u, c[u] + c[v]);
        add(v, u, c[v]);
    }

    sum[pos[u]] += cnt[-c[u]];
    cnt[0]--;

    for (int v : g[u]) {
        if (vis[v]) continue;

        del(v, u, c[v]);
    }

    std::for_each(g[u].rbegin(), g[u].rend(), [&](int v) -> void {
        if (vis[v]) return;

        calc(v, u, c[u] + c[v]);
        add(v, u, c[v]);
    });

    for (int v : g[u]) {
        if (vis[v]) continue;

        del(v, u, c[v]);
    }

    for (int v : g[u]) {
        if (vis[v]) continue;

        root = 0;
        get_root(v, 0, siz[v]);
        get_root(root, 0, siz[v]);
        solve(root);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        c[i] = x ? 1 : -1;
    }

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        pos[a[i]] = i;
    }

    get_root(1, 0, n);
    get_root(root, 0, n);
    solve(root);

    std::partial_sum(sum + 1, sum + 1 + n, sum + 1);

    for (int l = 1, r = 1; l <= n; l++) {
        while (r <= n && sum[r] - sum[l - 1] <= sum[n] - sum[r] + sum[l - 1]) r++;

        ans += n - r + 1;
    }

    cout << ans << endl;

    return 0;
}
