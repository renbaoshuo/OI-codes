#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Limits
const int N = 100005;

// Variables
int n;
char op;

// Persistent Segment Tree
int p, cnt, root[N];
int insert(int, int, int, int);
int query(int, int, int, int);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op == 'T') {
            char x;
            cin >> x;
            int k = x - 'a';
            root[p + 1] = insert(root[p], 1, n, k);
            p++;
        } else if (op == 'U') {
            int x;
            cin >> x;
            root[p + 1] = root[std::max(p - x, 0)];
            p++;
        } else {
            int x;
            cin >> x;
            cout << char(query(root[p], 1, n, x) + 'a') << endl;
        }
    }
    return 0;
}

// Persistent Segment Tree

struct node {
    int l, r, s, d;

    node()
        : l(0), r(0), s(0), d(0) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0), d(0) {}
} tr[N << 5];

int insert(int p, int l, int r, int x) {
    int q = ++cnt;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].s = 1;
        tr[q].d = x;
        return q;
    }
    int mid = l + r >> 1;
    if (tr[tr[q].l].s < mid - l + 1) {
        tr[q].l = insert(tr[q].l, l, mid, x);
    } else {
        tr[q].r = insert(tr[q].r, mid + 1, r, x);
    }
    tr[q].s = tr[tr[q].l].s + tr[tr[q].r].s;
    return q;
}

int query(int p, int l, int r, int x) {
    if (l == r) return tr[p].d;
    int mid = l + r >> 1;
    if (x <= mid) return query(tr[p].l, l, mid, x);
    return query(tr[p].r, mid + 1, r, x);
}
