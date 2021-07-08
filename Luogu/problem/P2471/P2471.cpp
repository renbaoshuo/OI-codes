#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, max;

    node() {
        l = r = max = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        max = 0;
    }
} tr[50005 << 2];

int n, m, x, y, a[50005];
map<int, int> m1;

void pushup(int u) {
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].max = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].max;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    int s = 0;
    if (l <= mid) s = max(s, query(u << 1, l, r));
    if (r > mid) s = max(s, query(u << 1 | 1, l, r));
    return s;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        m1[x] = i;
        a[i] = y;
    }
    build(1, 1, n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> y >> x;
        if (y >= x) {
            cout << "false" << endl;
            continue;
        }
        bool exist_x = m1.count(x);
        bool exist_y = m1.count(y);
        auto it_x = m1.lower_bound(x);
        auto it_y = m1.lower_bound(y);
        if (!exist_x) {
            if (!exist_y) {
                cout << "maybe" << endl;
            } else {
                if (query(1, m1[y] + 1, (it_x == m1.end() ? (--m1.end())->second : it_x->second - 1)) < a[m1[x]]) {
                    cout << "maybe" << endl;
                } else {
                    cout << "false" << endl;
                }
            }
        } else {
            if (exist_y) {
                if (a[m1[y]] < a[m1[x]]) {
                    cout << "false" << endl;
                } else if (query(1, m1[y] + 1, m1[x] - 1) >= a[m1[x]]) {
                    cout << "false" << endl;
                } else if (x - y == m1[x] - m1[y]) {
                    cout << "true" << endl;
                } else {
                    cout << "maybe" << endl;
                }
            } else {
                if (it_y == m1.end() || query(1, it_y->second, m1[x] - 1) >= a[m1[x]]) {
                    cout << "false" << endl;
                } else {
                    cout << "maybe" << endl;
                }
            }
        }
    }
    return 0;
}
