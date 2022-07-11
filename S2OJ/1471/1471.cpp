#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, m, a[N];
long long ans;

struct node {
    int l, r, s;

    node()
        : l(0), r(0), s(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0) {}
} tr[N << 2];

void pushup(int u) {
    tr[u].s = tr[u << 1].s | tr[u << 1 | 1].s;
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

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].s;

    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;

    if (l <= mid) res |= query(u << 1, l, r);
    if (r > mid) res |= query(u << 1 | 1, l, r);

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

    for (int i = 1, j = 1; i <= n; i++) {
        while (j < i && query(1, j, i) >= m) j++;

        ans += i - j;
    }

    cout << ans << endl;

    return 0;
}
