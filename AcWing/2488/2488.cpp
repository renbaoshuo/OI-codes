#include <iostream>
#include <limits>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int n, m, a[N];

struct node : public std::multiset<int> {
    int l, r;

    node()
        : l(0), r(0) {}

    node(int _l, int _r)
        : l(_l), r(_r) {
        insert(std::numeric_limits<int>::min());
        insert(std::numeric_limits<int>::max());
    }
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    for (int i = l; i <= r; i++) {
        tr[u].insert(a[i]);
    }

    if (l == r) return;

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int p, int x) {
    tr[u].erase(tr[u].find(a[p]));
    tr[u].insert(x);

    if (tr[u].l == tr[u].r) return;

    int mid = tr[u].l + tr[u].r >> 1;

    if (p <= mid) modify(u << 1, p, x);
    else modify(u << 1 | 1, p, x);
}

int query(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return *--tr[u].lower_bound(x);
    }

    int mid = tr[u].l + tr[u].r >> 1;
    int res = std::numeric_limits<int>::min();

    if (l <= mid) res = std::max(res, query(u << 1, l, r, x));
    if (r > mid) res = std::max(res, query(u << 1 | 1, l, r, x));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int p, x;

            cin >> p >> x;

            modify(1, p, x);
            a[p] = x;
        } else {  // op == 2
            int l, r, x;

            cin >> l >> r >> x;

            cout << query(1, l, r, x) << endl;
        }
    }

    return 0;
}
