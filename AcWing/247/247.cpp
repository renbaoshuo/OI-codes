#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<double> ys;

struct segment {
    double x, y1, y2;
    int k;

    segment()
        : x(0), y1(0), y2(0), k(0) {}
    segment(double _x, double _y1, double _y2, int _k)
        : x(_x), y1(_y1), y2(_y2), k(_k) {}

    bool operator<(const segment& b) const {
        return x < b.x;
    }
} seg[10005 << 1];

struct node {
    int l, r, cnt;
    double len;

    node()
        : l(0), r(0), cnt(0), len(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), cnt(0), len(0) {}
} tr[10005 << 3];

int find(double y) {
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u) {
    if (tr[u].cnt) {
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    } else if (tr[u].l != tr[u].r) {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    } else {
        tr[u].len = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].cnt += x;
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, x);
        if (r > mid) modify(u << 1 | 1, l, r, x);
    }
    pushup(u);
}

int main() {
    while (cin >> n, n) {
        ys.clear();
        double ans = 0;
        cout << "Test case #" << ++k << endl;
        for (int i = 0, j = 0; i < n; i++) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            seg[j++] = segment(x1, y1, y2, 1);
            seg[j++] = segment(x2, y1, y2, -1);
            ys.push_back(y1);
            ys.push_back(y2);
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        build(1, 0, ys.size() - 2);
        sort(seg, seg + n * 2);
        for (int i = 0; i < n * 2; i++) {
            if (i > 0) {
                ans += tr[1].len * (seg[i].x - seg[i - 1].x);
            }
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }
        cout << "Total explored area: " << fixed << setprecision(2) << ans << endl;
        cout << endl;
    }
    return 0;
}
