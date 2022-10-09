#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, m, fa[N];
std::vector<int> son[N];

struct node {
    int l, r, max, min;

    node(int _l = 0, int _r = 0)
        : l(_l),
          r(_r),
          max(std::numeric_limits<int>::min()),
          min(std::numeric_limits<int>::max()) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].min = std::min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        tr[u].max = tr[u].min = l;

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);

    pushup(u);
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r) {
        tr[u].max = tr[u].min = v;

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, x, v);

    pushup(u);
}

std::pair<int, int> query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return std::make_pair(tr[u].max, tr[u].min);

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);

    auto res1 = query(u << 1, l, r);
    auto res2 = query(u << 1 | 1, l, r);

    return std::make_pair(std::max(res1.first, res2.first), std::min(res1.second, res2.second));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;

        son[i].emplace_back(i);
    }

    build(1, 1, n);

    while (m--) {
        int op, l, r;

        cin >> op >> l >> r;

        if (op == 1) {
            int x = fa[l],
                y = fa[r];

            if (x != y) {
                if (son[x].size() < son[y].size()) std::swap(x, y);

                for (int v : son[y]) {
                    modify(1, v, fa[v] = x);
                    son[x].emplace_back(v);
                }

                son[y].clear();
            }
        } else {  // op == 2
            if (l > r) std::swap(l, r);

            auto res = query(1, l, r);

            cout << (res.first == res.second ? "zzy" : "orz") << endl;
        }
    }

    return 0;
}
