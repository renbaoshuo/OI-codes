#pragma GCC optimize("Ofast")

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <vector>

const int N = 2e5 + 5;

int n;
long long ans;
std::vector<int> ys;

template <typename T>
void read(T& x) {
    int f = 1;
    char ch = getchar();
    x = 0;
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

struct segment {
    int x, y1, y2, k;

    segment()
        : x(0), y1(0), y2(0), k(0) {}
    segment(int _x, int _y1, int _y2, int _k)
        : x(_x), y1(_y1), y2(_y2), k(_k) {}

    bool operator<(const segment& b) const {
        return x == b.x ? k > b.k : x < b.x;
    }
} seg[N << 1];

struct rectangle {
    int x1, y1, x2, y2;
} q[N];

struct node {
    int l, r;
    long long cnt, len;

    node()
        : l(0), r(0), cnt(0), len(0) {}
    node(int _l, int _r)
        : l(_l), r(_r), cnt(0), len(0) {}
} tr[N << 3];

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

void solve() {
    std::sort(ys.begin(), ys.end());
    std::sort(seg, seg + n * 2);
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    build(1, 0, ys.size() - 2);
    for (int i = 0; i < n * 2; i++) {
        int last = tr[1].len;
        if (seg[i].y1 == seg[i].y2) continue;
        modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        ans += abs(tr[1].len - last);
    }
    ys.clear();
}

int main() {
    read(n);
    for (int i = 0; i < n; i++) {
        read(q[i].x1), read(q[i].y1), read(q[i].x2), read(q[i].y2);
    }
    for (int i = 0, j = 0; i < n; i++) {
        seg[j++] = segment(q[i].x1, q[i].y1, q[i].y2, 1);
        seg[j++] = segment(q[i].x2, q[i].y1, q[i].y2, -1);
        ys.push_back(q[i].y1);
        ys.push_back(q[i].y2);
    }
    solve();
    for (int i = 0, j = 0; i < n; i++) {
        seg[j++] = segment(q[i].y1, q[i].x1, q[i].x2, 1);
        seg[j++] = segment(q[i].y2, q[i].x1, q[i].x2, -1);
        ys.push_back(q[i].x1);
        ys.push_back(q[i].x2);
    }
    solve();
    printf("%lld\n", ans);
    return 0;
}
