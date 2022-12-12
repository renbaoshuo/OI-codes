#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e4 + 5;

int n, q, lst;
int cnt, root[N];
std::pair<int, int> a[N];

struct node {
    int l, r, l_max, r_max, sum;
} tr[N << 5];

void pushup(int u) {
    tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
    tr[u].l_max = std::max(tr[tr[u].l].l_max, tr[tr[u].l].sum + tr[tr[u].r].l_max);
    tr[u].r_max = std::max(tr[tr[u].r].r_max, tr[tr[u].r].sum + tr[tr[u].l].r_max);
}

int build(int l, int r) {
    int p = ++cnt;

    if (l == r) {
        tr[p].l_max = tr[p].r_max = tr[p].sum = 1;

        return p;
    }

    int mid = l + r >> 1;

    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);

    pushup(p);

    return p;
}

int insert(int p, int l, int r, int x, int y) {
    int q = ++cnt;
    tr[q] = tr[p];

    if (l == r) {
        tr[q].l_max = tr[q].r_max = tr[q].sum = y;

        return q;
    }

    int mid = l + r >> 1;

    if (x <= mid) tr[q].l = insert(tr[q].l, l, mid, x, y);
    else tr[q].r = insert(tr[q].r, mid + 1, r, x, y);

    pushup(q);

    return q;
}

int query_sum(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr[p].sum;

    int mid = (l + r) >> 1;
    int res = 0;

    if (ql <= mid) res += query_sum(tr[p].l, l, mid, ql, qr);
    if (qr > mid) res += query_sum(tr[p].r, mid + 1, r, ql, qr);

    return res;
}

int query_l_max(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr[p].l_max;

    int mid = (l + r) >> 1;

    if (qr <= mid) return query_l_max(tr[p].l, l, mid, ql, qr);
    if (ql > mid) return query_l_max(tr[p].r, mid + 1, r, ql, qr);

    return std::max(query_l_max(tr[p].l, l, mid, ql, qr), query_sum(tr[p].l, l, mid, ql, qr) + query_l_max(tr[p].r, mid + 1, r, ql, qr));
}

int query_r_max(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr[p].r_max;

    int mid = (l + r) >> 1;

    if (qr <= mid) return query_r_max(tr[p].l, l, mid, ql, qr);
    if (ql > mid) return query_r_max(tr[p].r, mid + 1, r, ql, qr);

    return std::max(query_r_max(tr[p].r, mid + 1, r, ql, qr), query_sum(tr[p].r, mid + 1, r, ql, qr) + query_r_max(tr[p].l, l, mid, ql, qr));
}

bool check(int k, int a, int b, int c, int d) {
    int sum = 0;

    if (b + 1 <= c - 1) sum += query_sum(root[k], 1, n, b + 1, c - 1);

    sum += query_r_max(root[k], 1, n, a, b);
    sum += query_l_max(root[k], 1, n, c, d);

    return sum >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;

        a[i].second = i;
    }

    std::sort(a + 1, a + 1 + n);

    root[0] = build(1, n);

    for (int i = 1; i <= n; i++) {
        root[i] = insert(root[i - 1], 1, n, a[i].second, -1);
    }

    cin >> q;

    while (q--) {
        std::vector<int> q(4);

        for (int& x : q) cin >> x;

        std::transform(q.begin(), q.end(), q.begin(), [&](int x) -> int {
            return (x + lst) % n + 1;
        });
        std::sort(q.begin(), q.end());

        int l = 0, r = n - 1, res = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;

            if (check(mid, q[0], q[1], q[2], q[3])) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        cout << (lst = a[res + 1].first) << endl;
    }

    return 0;
}
