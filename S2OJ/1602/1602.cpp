#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15,
          M = 1e5 + 5;

int n, m, q;
int cnt, id[N][N];
long long a[N][M], sum[N][M];

class SegmentTree {
  private:
    struct node {
        int l, r;
        long long sum, pre, suf, max;

        node(int _l = 0, int _r = 0)
            : l(_l), r(_r), sum(0), pre(0), suf(0), max(std::numeric_limits<int>::min()) {}
    } tr[M << 2];

    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
        tr[u].pre = std::max(tr[u << 1].pre, tr[u << 1].sum + tr[u << 1 | 1].pre);
        tr[u].suf = std::max(tr[u << 1 | 1].suf, tr[u << 1].suf + tr[u << 1 | 1].sum);
        tr[u].max = std::max({tr[u << 1].max, tr[u << 1 | 1].max, tr[u << 1].suf + tr[u << 1 | 1].pre});
    }

    void build(int u, int l, int r, const int& id_l, const int& id_r) {
        tr[u] = node(l, r);

        if (l == r) {
            tr[u].sum = tr[u].pre = tr[u].suf = tr[u].max = sum[id_r][l] - sum[id_l - 1][l];

            return;
        }

        int mid = l + r >> 1;

        build(u << 1, l, mid, id_l, id_r);
        build(u << 1 | 1, mid + 1, r, id_l, id_r);

        pushup(u);
    }

    void modify(int u, int p, long long v) {
        if (tr[u].l == p && tr[u].r == p) {
            tr[u].sum = tr[u].pre = tr[u].suf = tr[u].max += v;

            return;
        }

        int mid = tr[u].l + tr[u].r >> 1;

        if (p <= mid) modify(u << 1, p, v);
        else modify(u << 1 | 1, p, v);

        pushup(u);
    }

    node query(int u, int l, int r) {
        if (l <= tr[u].l && tr[u].r <= r) {
            return tr[u];
        }

        int mid = tr[u].l + tr[u].r >> 1;

        if (r <= mid) {
            return query(u << 1, l, r);
        }

        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }

        node res;
        node left = query(u << 1, l, r);
        node right = query(u << 1 | 1, l, r);

        res.sum = left.sum + right.sum;
        res.pre = std::max(left.pre, left.sum + right.pre);
        res.suf = std::max(left.suf + right.sum, right.suf);
        res.max = std::max({left.max, right.max, left.suf + right.pre});

        return res;
    }

  public:
    void build(int l, int r, int id_l, int id_r) {
        build(1, l, r, id_l, id_r);
    }

    void modify(int p, long long v) {
        modify(1, p, v);
    }

    node query(int l, int r) {
        return query(1, l, r);
    }
} tr[60];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];

            sum[i][j] = sum[i - 1][j] + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            tr[id[i][j] = ++cnt].build(1, m, i, j);
        }
    }

    cin >> q;

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y, v;

            cin >> x >> y >> v;

            for (int i = 1; i <= x; i++) {
                for (int j = x; j <= n; j++) {
                    tr[id[i][j]].modify(y, v - a[x][y]);
                }
            }

            a[x][y] = v;
        } else {  // op == 2
            int x1, y1, x2, y2;
            long long res = std::numeric_limits<long long>::min();

            cin >> x1 >> y1 >> x2 >> y2;

            for (int i = x1; i <= x2; i++) {
                for (int j = i; j <= x2; j++) {
                    res = std::max(res, tr[id[i][j]].query(y1, y2).max);
                }
            }

            cout << res << endl;
        }
    }

    return 0;
}
