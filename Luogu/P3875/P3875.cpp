#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, k;
long long ans;
std::vector<int> ys;

struct Segment {
    int x, y1, y2, k;

    Segment()
        : x(0), y1(0), y2(0), k(0) {}

    Segment(int _x, int _y1, int _y2, int _k)
        : x(_x), y1(_y1), y2(_y2), k(_k) {}

    bool operator<(const Segment& b) const {
        return x < b.x;
    }
};

struct node {
    int l, r;
    long long cnt, len;

    node(const int& _l = 0, const int& _r = 0)
        : l(_l), r(_r), cnt(0), len(0) {}
} tr[N << 2];

inline int find(int y) {
    return std::lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

inline void pushup(int u) {
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
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    std::vector<Segment> seg;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            if (y1 > y2) std::swap(y1, y2);

            x1--, x2++;
        } else if (y1 == y2) {
            if (x1 > x2) std::swap(x1, x2);

            y1--, y2++;
        }

        seg.emplace_back(x1, y1, y2, 1);
        seg.emplace_back(x2, y1, y2, -1);

        ys.push_back(y1);
        ys.push_back(y2);
    }

    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

    build(1, 0, ys.size() - 2);
    std::sort(seg.begin(), seg.end());

    for (int i = 0; i < seg.size(); i++) {
        if (i > 0) {
            ans += tr[1].len * (seg[i].x - seg[i - 1].x);
        }

        modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
    }

    cout << ans << endl;

    return 0;
}
