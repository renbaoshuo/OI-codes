#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int m, d, cnt;
long long t;

struct node {
    int l, r;
    long long max;
} tr[N << 2];

void pushup(int u) {
    tr[u].max = std::max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build(int u, int l, int r) {
    tr[u].l = l;
    tr[u].r = r;

    if (l == r) {
        tr[u].max = 0;

        return;
    }

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);          // [l, mid]
    build(u << 1 | 1, mid + 1, r);  // [mid + 1, r]

    pushup(u);
}

void modify(int u, int pos, long long val) {
    if (tr[u].l == pos && tr[u].r == pos) {
        tr[u].max = val;

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (pos <= mid) modify(u << 1, pos, val);
    else modify(u << 1 | 1, pos, val);

    pushup(u);
}

long long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;

    int mid = (tr[u].l + tr[u].r) >> 1;
    long long res = 0;

    if (l <= mid) res = std::max(res, query(u << 1, l, r));
    if (r > mid) res = std::max(res, query(u << 1 | 1, l, r));

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> d;

    build(1, 1, m);

    while (m--) {
        char op;

        cin >> op;

        if (op == 'Q') {
            int l;

            cin >> l;

            t = query(1, cnt - l + 1, cnt);

            cout << t << endl;
        } else {  // op == 2
            long long x;

            cin >> x;

            modify(1, ++cnt, ((t + x) % d + d) % d);
        }
    }

    return 0;
}
