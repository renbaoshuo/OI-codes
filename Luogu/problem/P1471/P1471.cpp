#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    double s, s2, d;

    node() {
        l = r = 0;
        s = s2 = d = 0.00;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = s2 = d = 0.00;
    }
} tr[100005 << 2];
int n, m, op, x, y;
double k, a[100005];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].s2 = tr[u << 1].s2 + tr[u << 1 | 1].s2;
}

void pushdown(int u) {
    if (!tr[u].d) return;
    tr[u << 1].d += tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;
    tr[u << 1].s2 += tr[u << 1].s * tr[u].d * 2 + (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d * tr[u].d;
    tr[u << 1 | 1].s2 += tr[u << 1 | 1].s * tr[u].d * 2 + (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d * tr[u].d;
    tr[u << 1].s += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].d;
    tr[u << 1 | 1].s += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].d;
    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        tr[u].s2 = a[l] * a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

double query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    double s = 0.00;
    pushdown(u);
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

double query2(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s2;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    double s = 0.00;
    pushdown(u);
    if (l <= mid) s += query2(u << 1, l, r);
    if (r > mid) s += query2(u << 1 | 1, l, r);
    return s;
}

void modify(int u, int l, int r, double d) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d += d;
        tr[u].s2 += tr[u].s * d * 2 + (tr[u].r - tr[u].l + 1) * d * d;
        tr[u].s += (tr[u].r - tr[u].l + 1) * d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, d);
    if (r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> k;
            modify(1, x, y, k);
        } else if (op == 2) {
            cout << fixed << setprecision(4) << (double)query(1, x, y) / (y - x + 1) << endl;
        } else if (op == 3) {
            cout << fixed << setprecision(4) << (double)(query2(1, x, y) / ((y - x + 1) * 1.00)) - pow(query(1, x, y) / ((y - x + 1) * 1.00), 2) << endl;
        }
    }
    return 0;
}
