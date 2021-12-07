#include <bits/stdc++.h>

using namespace std;

int n, m, op, x, y, a[300005];
int cnt, d[1000005], f[1000005], p[1000005];
bool v[1000005];

/**
 * Calculate the number of positive divisors of
 * positive integers from 1 to 1,000,000.
 */
void calc() {
    d[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!v[i]) {
            v[i] = true;
            p[++cnt] = i;
            f[i] = 1;
            d[i] = 2;
        }
        for (int j = 1; j <= cnt && i * p[j] <= 1000000; j++) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) {
                f[i * p[j]] = f[i] + 1;
                d[i * p[j]] = 1ll * d[i] / f[i * p[j]] * (f[i * p[j]] + 1);
                break;
            }
            f[i * p[j]] = 1;
            d[i * p[j]] = d[i] * 2;
        }
    }
}

// Segment Tree
void pushup(int);
void build(int, int, int);
void modify(int, int, int);
long long query(int, int, int);

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    calc();
    while (m--) {
        cin >> op >> x >> y;
        if (op == 1) {
            modify(1, x, y);
        } else {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}

// === Segment Tree ===

struct node {
    int l, r;
    long long s, m;

    node()
        : l(0), r(0), s(0), m(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), m(0) {}
} tr[300005 << 2];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = tr[u].m = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r) {
    if (tr[u].m <= 2) return;
    if (tr[u].l == tr[u].r) {
        tr[u].s = tr[u].m = d[tr[u].s];
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r);
    if (r > mid) modify(u << 1 | 1, l, r);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s;
    int mid = tr[u].l + tr[u].r >> 1;
    long long sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}
