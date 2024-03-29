#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    long long s, d;

    node() {
        l = r = s = d = 0;
    }

    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = d = 0;
    }
} tr[1000005 << 2];

int n, q, op, l, r;
long long x, a[1000005];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void pushdown(int u) {
    if (!tr[u].d) return;
    tr[u << 1].d += tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, long long d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d += d;
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    pushdown(u);
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%lld", &x);
            modify(1, l, r, x);
        } else if (op == 2) {
            printf("%lld\n", query(1, l, r));
        }
    }
    return 0;
}
