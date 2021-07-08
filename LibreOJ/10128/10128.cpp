#include <bits/stdc++.h>

using namespace std;

int n, m, k, l, r;
long long a[100005];
bool flag = true;

struct node {
    int l, r;
    long long s;
    bool allIsOne;

    node() {
        l = r = s = 0;
        allIsOne = false;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = 0;
        allIsOne = false;
    }
} tr[100005 << 2];

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].allIsOne = tr[u << 1].allIsOne && tr[u << 1 | 1].allIsOne;
    return;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        tr[u].allIsOne = (a[l] == 1 ? true : false);
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r) {
    if (tr[u].allIsOne) return;
    if (tr[u].l == tr[u].r) {
        tr[u].s = floor(sqrt(tr[u].s));
        tr[u].allIsOne = (tr[u].s == 1 ? true : false);
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r);
    if (r > mid) modify(u << 1 | 1, l, r);
    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    long long s = 0;
    if (l <= mid) s += query(u << 1, l, r);
    if (r > mid) s += query(u << 1 | 1, l, r);
    return s;
}

int main() {
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        flag = a[i] == 0;
    }
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    build(1, 1, n);
    scanf("%d", &m);
    for (register int i = 0; i < m; i++) {
        scanf("%d%d%d", &k, &l, &r);
        if (l > r) swap(l, r);
        if (k == 1) {
            printf("%lld\n", query(1, l, r));
        } else if (k == 2) {
            modify(1, l, r);
        }
    }
    return 0;
}