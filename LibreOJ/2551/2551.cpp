#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5,
          K = 1e6 + 5;

int n, m, a[N], cnt, root[N];

struct node {
    int l, r, siz;
    long long sum;
} tr[N << 5];

int build(int l, int r) {
    int p = ++cnt;

    if (l == r) return p;

    int mid = l + r >> 1;

    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);

    return p;
}

int insert(int p, int l, int r, int x) {
    int q = ++cnt;

    tr[q] = tr[p];
    tr[q].siz++;
    tr[q].sum += x;

    if (l == r) return q;

    int mid = l + r >> 1;

    if (x <= mid) {
        tr[q].l = insert(tr[p].l, l, mid, x);
    } else {
        tr[q].r = insert(tr[p].r, mid + 1, r, x);
    }

    tr[q].siz = tr[tr[q].l].siz + tr[tr[q].r].siz;
    tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;

    return q;
}

long long query(int p, int q, int l, int r, int f, int k) {
    int siz = tr[p].siz - tr[q].siz;
    long long sum = tr[p].sum - tr[q].sum;

    if (!siz) return 0;
    if (l >= k + f) return sum - static_cast<long long>(2 * k + 2 * f + siz - 1) * siz / 2;
    if (r <= k + f + siz - 1) return static_cast<long long>(2 * k + 2 * f + siz - 1) * siz / 2 - sum;

    int siz_l = tr[tr[p].l].siz - tr[tr[q].l].siz;
    int mid = l + r >> 1;

    return query(tr[p].l, tr[q].l, l, mid, f, k)
         + query(tr[p].r, tr[q].r, mid + 1, r, f + siz_l, k);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    root[0] = build(1, 1000000);

    for (int i = 1; i <= n; i++) {
        root[i] = insert(root[i - 1], 1, 1000000, a[i]);
    }

    for (int i = 1, l, r, k; i <= m; i++) {
        cin >> l >> r >> k;

        cout << query(root[r], root[l - 1], 1, 1000000, 0, k) << endl;
    }

    return 0;
}
