#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m, q;
long long a[N], b[N];

struct node {
    int l, r, cnt;
    long long min, max;

    node(int _l = 0, int _r = 0)
        : l(_l), r(_r), cnt(0), min(INF), max(-INF) {}
} tr1a[N << 2], tr1b[N << 2], tr2a[N << 2], tr2b[N << 2];

void pushup(node* tr, int u) {
    tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
    tr[u].min = std::min(tr[u << 1].min, tr[u << 1 | 1].min);
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build1(node* tr, long long* a, int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        if (a[l] >= 0) {
            tr[u].max = tr[u].min = a[l];
            tr[u].cnt = 1;
        }

        return;
    }

    int mid = l + r >> 1;

    build1(tr, a, u << 1, l, mid);
    build1(tr, a, u << 1 | 1, mid + 1, r);

    pushup(tr, u);
}

void build2(node* tr, long long* a, int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) {
        if (a[l] <= 0) {
            tr[u].max = tr[u].min = a[l];
            tr[u].cnt = 1;
        }

        return;
    }

    int mid = l + r >> 1;

    build2(tr, a, u << 1, l, mid);
    build2(tr, a, u << 1 | 1, mid + 1, r);

    pushup(tr, u);
}

long long query_min(node* tr, int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].min;

    int mid = tr[u].l + tr[u].r >> 1;
    long long res = INF;

    if (l <= mid) res = std::min(res, query_min(tr, u << 1, l, r));
    if (r > mid) res = std::min(res, query_min(tr, u << 1 | 1, l, r));

    return res;
}

long long query_max(node* tr, int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;

    int mid = tr[u].l + tr[u].r >> 1;
    long long res = -INF;

    if (l <= mid) res = std::max(res, query_max(tr, u << 1, l, r));
    if (r > mid) res = std::max(res, query_max(tr, u << 1 | 1, l, r));

    return res;
}

int query_cnt(node* tr, int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].cnt;

    int mid = tr[u].l + tr[u].r >> 1;
    int cnt = 0;

    if (l <= mid) cnt += query_cnt(tr, u << 1, l, r);
    if (r > mid) cnt += query_cnt(tr, u << 1 | 1, l, r);

    return cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    build1(tr1a, a, 1, 1, n);
    build2(tr1b, a, 1, 1, n);
    build1(tr2a, b, 1, 1, m);
    build2(tr2b, b, 1, 1, m);

    while (q--) {
        int l1, r1, l2, r2;

        cin >> l1 >> r1 >> l2 >> r2;

        long long max_1a = query_max(tr1a, 1, l1, r1),
                  min_1a = query_min(tr1a, 1, l1, r1);
        long long max_1b = query_max(tr1b, 1, l1, r1),
                  min_1b = query_min(tr1b, 1, l1, r1);
        long long max_2a = query_max(tr2a, 1, l2, r2),
                  min_2a = query_min(tr2a, 1, l2, r2);
        long long max_2b = query_max(tr2b, 1, l2, r2),
                  min_2b = query_min(tr2b, 1, l2, r2);

        int cnt_1a = query_cnt(tr1a, 1, l1, r1),
            cnt_1b = query_cnt(tr1b, 1, l1, r1);
        int cnt_2a = query_cnt(tr2a, 1, l2, r2),
            cnt_2b = query_cnt(tr2b, 1, l2, r2);

        if (!cnt_1a) {      // 1. [l1, r1] 间无正数
            if (!cnt_2a) {  // a. [l2, r2] 间无正数
                cout << min_1b * max_2b << endl;
            } else if (!cnt_2b) {  // b [l2, r2] 间无负数
                cout << max_1b * max_2a << endl;
            } else {
                cout << max_1b * max_2a << endl;
            }
        } else if (!cnt_1b) {  // 2. [l1, r1] 间无负数
            if (!cnt_2a) {     // a. [l2, r2] 间无正数
                cout << min_1a * min_2b << endl;
            } else if (!cnt_2b) {  // b [l2, r2] 间无负数
                cout << max_1a * min_2a << endl;
            } else {
                cout << min_1a * min_2b << endl;
            }
        } else {
            if (!cnt_2a) {  // a. [l2, r2] 间无正数
                cout << min_1b * max_2b << endl;
            } else if (!cnt_2b) {  // b [l2, r2] 间无负数
                cout << max_1a * min_2a << endl;
            } else {
                cout << std::max(max_1b * max_2a, min_1a * min_2b) << endl;
            }
        }
    }

    return 0;
}
