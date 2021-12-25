#include <cctype>
#include <cstdio>

const int N = 1000005;

int n, q, a[N], pre[N];

// Helpers
void read(int &);

// Segment Tree
int cnt, root[N];
int build(int, int);
int insert(int, int, int, int, int);
int query(int, int, int, int);

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
    }
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        if (!pre[a[i]]) {
            root[i] = insert(root[i - 1], 1, n, i, 1);
        } else {
            int tmp = insert(root[i - 1], 1, n, pre[a[i]], -1);
            root[i] = insert(tmp, 1, n, i, 1);
        }
        pre[a[i]] = i;
    }
    read(q);
    while (q--) {
        int l, r;
        read(l), read(r);
        printf("%d\n", query(root[r], 1, n, l));
    }
    return 0;
}

// === Helpers ===

void read(int &x) {
    x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
}

// === Segment Tree ===

struct node {
    int l, r, c;
} tr[N << 6];

inline void pushup(int u) {
    tr[u].c = tr[tr[u].l].c + tr[tr[u].r].c;
}

int build(int l, int r) {
    int p = ++cnt;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x, int v) {
    int q = ++cnt;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].c += v;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
        tr[q].l = insert(tr[p].l, l, mid, x, v);
    } else {
        tr[q].r = insert(tr[p].r, mid + 1, r, x, v);
    }
    pushup(q);
    return q;
}

int query(int u, int l, int r, int x) {
    if (l == r) return tr[u].c;
    int mid = l + r >> 1;
    if (x <= mid) return tr[tr[u].r].c + query(tr[u].l, l, mid, x);
    return query(tr[u].r, mid + 1, r, x);
}
