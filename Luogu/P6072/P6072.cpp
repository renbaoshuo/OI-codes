#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e4 + 5;

int n, t, c, tot, id[N], siz[N], dis[N << 1], pos[N << 1], ans[N << 1];
std::vector<std::pair<int, int>> g[N];
std::tuple<int, int, int> qs[N << 1];
int tr[N * 30][2], cnt[N * 30];

void insert(int x) {
    static int tot = 1;
    int p = 1;

    for (int i = 30; i >= 0; i--) {
        bool ch = (x >> i) & 1;

        if (!tr[p][ch]) {
            tr[p][ch] = ++tot;
        }

        p = tr[p][ch];
        cnt[p]++;
    }
}

int query(int x) {
    int p = 1;
    int res = 0;

    for (int i = 30; i >= 0; i--) {
        int ch = (x >> i) & 1;

        if (cnt[tr[p][ch ^ 1]]) {
            res |= 1 << i;
            p = tr[p][ch ^ 1];
        } else {
            p = tr[p][ch];
        }
    }

    return res;
}

void remove(int x) {
    int p = 1;

    for (int i = 30; i >= 0; i--) {
        int ch = (x >> i) & 1;

        p = tr[p][ch];
        cnt[p]--;
    }
}

void dfs(int u, int f, int w) {
    static int cnt = 0;

    id[u] = ++cnt;
    siz[u] = 1;
    dis[id[u]] = dis[id[f]] ^ w;

    std::for_each(g[u].rbegin(), g[u].rend(), [&](auto e) {
        int v = e.first,
            w = e.second;

        if (v == f) return;

        dfs(v, u, w);

        siz[u] += siz[v];
    });
}

int calc(int l, int r) {
    int res = 0;

    for (int i = l; i <= r; i++) {
        res = std::max(res, query(dis[i]));
        insert(dis[i]);
    }

    for (int i = l; i <= r; i++) {
        remove(dis[i]);
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x, y, w; i < n; i++) {
        cin >> x >> y >> w;

        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }

    dfs(1, 0, 0);

    for (int i = 2; i <= n; i++) {
        qs[++tot] = {id[i], id[i] + siz[i] - 1, i};
        qs[++tot] = {id[i] + siz[i], id[i] + n - 1, i};
    }

    std::copy_n(dis + 1, n, dis + 1 + n);

    n <<= 1;
    t = std::sqrt(n);

    for (int i = 1; i <= n; i++) {
        pos[i] = (i - 1) / t + 1;
    }

    std::sort(qs + 1, qs + tot + 1, [&](auto lhs, auto rhs) -> bool {
        int p = pos[std::get<0>(lhs)],
            q = pos[std::get<0>(rhs)];
        int x = std::get<1>(lhs),
            y = std::get<1>(rhs);

        return p == q ? x < y : p < q;
    });

    for (int i = 1, p = 1; i <= pos[n]; i++) {
        int r = std::min(i * t, n),
            x = r + 1,
            y = r,
            res = 0;

        for (; pos[std::get<0>(qs[p])] == i; p++) {
            int ql, qr, id;

            std::tie(ql, qr, id) = qs[p];

            if (pos[qr] == i) {
                ans[id] += calc(ql, qr);

                continue;
            }

            while (y < qr) {
                res = std::max(res, query(dis[++y]));
                insert(dis[y]);
            }

            int tmp = res;

            while (x > ql) {
                res = std::max(res, query(dis[--x]));
                insert(dis[x]);
            }

            while (x <= r) remove(dis[x++]);

            ans[id] += res;
            res = tmp;
        }

        while (y > r) remove(dis[y--]);
    }

    cout << *std::max_element(ans + 1, ans + 1 + n) << endl;

    return 0;
}
