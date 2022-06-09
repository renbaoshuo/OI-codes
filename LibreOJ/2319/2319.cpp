#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

struct node {
    int l, r, d;

    node()
        : l(0), r(0), d(0) {}
} tr[N << 4];

int n, m, q, max, cnt, root[N];
std::vector<long long> r[N];

int query(int u, int l, int r, int x) {
    if (l == r) return l;

    int mid = l + r >> 1;
    int c = mid - l + 1 - tr[tr[u].l].d;

    if (x <= c) return query(tr[u].l, l, mid, x);
    return query(tr[u].r, mid + 1, r, x - c);
}

void remove(int &u, int l, int r, int x) {
    if (!u) u = ++cnt;
    tr[u].d++;

    if (l == r) return;

    int mid = l + r >> 1;
    if (x <= mid) remove(tr[u].l, l, mid, x);
    else remove(tr[u].r, mid + 1, r, x);
}

long long row(int x, int y) {
    int p = query(root[x], 1, max, y);
    remove(root[x], 1, max, p);
    return p < m ? 1ll * (x - 1) * m + p : r[x][p - m];
}

long long col(int y) {
    int p = query(root[0], 1, max, y);
    remove(root[0], 1, max, p);
    return p <= n ? 1ll * p * m : r[0][p - n - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    max = std::max(n, m) + q;

    for (int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;

        long long p;
        if (y == m) {  // 最后一列
            p = col(x);
            r[0].push_back(p);
        } else {
            p = row(x, y);
            r[0].push_back(p);
            r[x].push_back(col(x));
        }

        cout << p << endl;
    }

    return 0;
}
