#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5,
          M = 1e5 + 5;

int n, m, q, cnt, a[N];
std::map<int, int> map;
std::tuple<int, int, int, int> ops[N];
bool f[(1 << 10) + 5][M];

struct node {
    int l, r, d, s;

    node(int _l = 0, int _r = 0)
        : l(_l), r(_r), d(0), s(0) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].s = tr[u << 1].s | tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (!tr[u].d) return;

    tr[u << 1].s = tr[u << 1 | 1].s = 1 << map[tr[u].d];
    tr[u << 1].d = tr[u << 1 | 1].d = tr[u].d;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].s = 1 << map[a[l]];

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s = 1 << map[x];
        tr[u].d = x;

        return;
    }

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);

    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s;

    pushdown(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;

    if (l <= mid) res |= query(u << 1, l, r);
    if (r > mid) res |= query(u << 1 | 1, l, r);

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (!map.count(a[i])) map[a[i]] = -1;
    }

    for (int i = 1, op, l, r, x; i <= q; i++) {
        cin >> op >> l >> r >> x;

        if (op == 1) {
            if (!map.count(x)) map[x] = -1;
        }

        ops[i] = std::make_tuple(op, l, r, x);
    }

    std::vector<int> nums;

    for (auto &item : map) {
        nums.emplace_back(item.first);
        item.second = cnt++;
    }

    f[0][0] = true;
    for (int s = 1; s < 1 << cnt; s++) {
        int p = __builtin_ctz(s);

        for (int i = 0; i <= m; i++) {
            f[s][i] |= f[s ^ (1 << p)][i];
        }

        for (int i = nums[p]; i <= m; i++) {
            f[s][i] |= f[s][i - nums[p]];
        }
    }

    build(1, 1, n);

    for (int i = 1, op, l, r, x; i <= q; i++) {
        std::tie(op, l, r, x) = ops[i];

        if (op == 1) {
            modify(1, l, r, x);
        } else {  // op == 2
            int s = query(1, l, r);

            cout << (f[s][x] ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
