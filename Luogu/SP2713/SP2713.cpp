#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 100005;

int t, n, m, op, x, y;
long long a[N];

struct node {
    int l, r;
    long long s, m;

    node()
        : l(0), r(0), s(0), m(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), s(0), m(0) {}
} * tr;
void pushup(int);
void build(int, int, int);
void modify(int, int, int);
long long query(int, int, int);

int main() {
    while (scanf("%d", &n) != EOF) {
        tr = new node[N << 2];
        printf("Case #%d:\n", ++t);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d", &op, &x, &y);
            if (x > y) std::swap(x, y);
            if (op == 0) {
                modify(1, x, y);
            } else {
                printf("%lld\n", query(1, x, y));
            }
        }
        delete[] tr;
        printf("\n");
    }
    return 0;
}

// === Segment Tree ===

inline void pushup(int u) {
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
    if (tr[u].m <= 1) return;
    if (tr[u].l == tr[u].r) {
        tr[u].s = tr[u].m = static_cast<long long>(std::floor(std::sqrt(tr[u].s)));
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
