#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const int N = 100005;

int n, m, l, r, k, a[N];
std::vector<int> nums;

// Helpers
int find(int);

// Segment Tree
int cnt, root[N];
int build(int, int);
int insert(int, int, int, int);
int query(int, int, int, int, int);

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.push_back(a[i]);
    }
    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    root[0] = build(0, nums.size() - 1);
    for (int i = 1; i <= n; i++) {
        root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
    }
    while (m--) {
        cin >> l >> r >> k;
        cout << nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)] << endl;
    }
    return 0;
}

// === Helpers ===

inline int find(int x) {
    return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

// === Segment Tree ===

struct node {
    int l, r, c;

    node()
        : l(0),
          r(0),
          c(0) {}
} tr[N << 5];

int build(int l, int r) {
    int p = ++cnt;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x) {
    int q = ++cnt;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].c++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid) {
        tr[q].l = insert(tr[p].l, l, mid, x);
    } else {
        tr[q].r = insert(tr[p].r, mid + 1, r, x);
    }
    tr[q].c = tr[tr[q].l].c + tr[tr[q].r].c;
    return q;
}

int query(int q, int p, int l, int r, int k) {
    if (l == r) return l;
    int c = tr[tr[q].l].c - tr[tr[p].l].c;
    int mid = l + r >> 1;
    if (k <= c) return query(tr[q].l, tr[p].l, l, mid, k);
    return query(tr[q].r, tr[p].r, mid + 1, r, k - c);
}
