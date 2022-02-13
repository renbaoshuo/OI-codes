#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

const int N = 2e5 + 5;

int n;
long long ans;
std::vector<int> ys;

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
        modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        ans += abs(tr[1].len - last);
    }
    ys.clear();
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
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
