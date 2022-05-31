#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n;
std::string op;

struct node {
    int l, r, s;
    bool none;

    node()
        : l(0), r(0), s(0), none(false) {}

    node(int _l, int _r)
        : l(_l), r(_r), s(0), none(false) {}
} tr[N << 2];

inline void pushdown(int u) {
    if (!tr[u].none) return;

    tr[u << 1].s = 0;
    tr[u << 1].none = true;
    tr[u << 1 | 1].s = 0;
    tr[u << 1 | 1].none = true;
    tr[u].none = false;
}

inline void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int x, int d) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].s += d;
        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) {
        modify(u << 1, x, d);
    } else {
        modify(u << 1 | 1, x, d);
    }

    pushup(u);
}

void clear(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].none = true;
        tr[u].s = 0;
        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;

    if (l <= mid) clear(u << 1, l, r);
    if (r > mid) clear(u << 1 | 1, l, r);

    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;

    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);

    return sum;
}

int find(int u, int x) {
    if (tr[u].l == tr[u].r) return tr[u].l;

    if (tr[u << 1].s >= x) return find(u << 1, x);
    return find(u << 1 | 1, x - tr[u << 1].s);
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    build(1, 1, n);

    while (cin >> op, op != "Quit") {
        if (op == "Add") {
            int t, x;
            cin >> t >> x;

            modify(1, t, x);
        } else if (op == "Remove") {
            int t;
            cin >> t;

            if (t > 1) {
                cout << query(1, 1, t - 1) << endl;
                clear(1, 1, t - 1);
            } else {
                cout << 0 << endl;
            }
        } else if (op == "Count") {
            int a, b;
            cin >> a >> b;

            cout << query(1, a, b) << endl;
        } else if (op == "List") {
            int x;
            cin >> x;

            if (x > tr[1].s) {
                cout << "No" << endl;
            } else {
                cout << find(1, tr[1].s - x + 1) << endl;
            }
        } else {  // op == "Quit"
            exit(0);
        }
    }

    return 0;
}
