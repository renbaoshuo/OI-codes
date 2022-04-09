#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

struct node {
    int l, r;
    long long s, d;

    node()
        : l(0), r(0), s(0), d(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 2];

int n, k;
long long x, t, ans, a[N], b[N];
bool flag[N];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

inline void pushdown(int u) {
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1].d += tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = b[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, long long d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        tr[u].d += d;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    long long sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    build(1, 1, n);

    for (int i = n; i >= k; i--) {
        if ((t = query(1, 1, i)) > 0) {
            x = std::ceil(1.0 * t / k);
            modify(1, i - k + 1, i, -x);
            ans += x;
        }
    }

    t = 0;
    for (int i = 1; i < k; i++) {
        t = std::max(t, (long long)ceil(1.0 * query(1, 1, i) / i));
    }

    cout << ans + t << endl;

    return 0;
}
