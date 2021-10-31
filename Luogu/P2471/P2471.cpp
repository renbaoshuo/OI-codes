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

const char* solve(int x, int y) {
    if (x == y) {
        return "true";
    } else if (x > y) {
        return "false";
    }
    auto p1 = m1.lower_bound(x);
    auto p2 = m1.lower_bound(y);
    if (p2 == m1.end() || p2->first != y) {
        if (p1 == m1.end() || p1->first != x) {
            return "maybe";
        }
        --p2;
        if (p1->second + 1 > p2->second || query(1, p1->second + 1, p2->second) < a[p1->second]) {
            return "maybe";
        } else {
            return "false";
        }
    }
    if (p1 == m1.end()) {
        return "maybe";
    }
    if (p1->first == x) {
        if (a[p1->second] < a[p2->second]) {
            return "false";
        }
        if (p1->second + 1 > p2->second - 1) {
            return y - x == p2->second - p1->second ? "true" : "maybe";
        } else {
            int mx = query(1, p1->second + 1, p2->second - 1);
            if (mx >= a[p2->second]) {
                return "false";
            } else {
                return y - x == p2->second - p1->second ? "true" : "maybe";
            }
        }
    } else {
        if (p1 == p2) {
            return "maybe";
        } else {
            int mx = query(1, p1->second, p2->second - 1);
            if (mx >= a[p2->second]) {
                return "false";
            } else {
                return "maybe";
            }
        }
    }
    return "";
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
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
