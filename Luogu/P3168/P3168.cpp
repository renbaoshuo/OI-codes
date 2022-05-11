#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int m, n, a[N];
std::vector<int> nums, s[N], e[N];

// Helpers
int find(int);

// Presistent Segment Tree
int cnt, root[N];

struct node {
    int l, r, c;
    long long s;

    node()
        : l(0), r(0), c(0), s(0) {}
} tr[N << 6];

int build(int, int);
int insert(int, int, int, int, int);
long long query(int, int, int, int);

int main() {
    std::ios::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r >> a[i];

        s[l].push_back(i);
        e[r + 1].push_back(i);

        nums.push_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    root[0] = build(0, nums.size() - 1);

    for (int i = 1; i <= n; i++) {
        root[i] = root[i - 1];

        for (int x : s[i]) {
            root[i] = insert(root[i], 0, nums.size() - 1, find(a[x]), 1);
        }

        for (int x : e[i]) {
            root[i] = insert(root[i], 0, nums.size() - 1, find(a[x]), -1);
        }
    }

    long long pre = 1;
    for (int i = 1, x, a, b, c; i <= n; i++) {
        cin >> x >> a >> b >> c;
        int k = 1 + (1ll * a * pre + b) % c;
        cout << (pre = k > tr[root[x]].c ? tr[root[x]].s
                                         : query(root[x], 0, nums.size() - 1, k))
             << endl;
    }

    return 0;
}

// === Helpers ===

inline int find(int x) {
    return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

// === President Segment Tree ===

int build(int l, int r) {
    int p = ++cnt;
    if (l == r) return p;

    int mid = l + r >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x, int v) {
    int q = ++cnt;
    tr[q] = tr[p];

    tr[q].c += v;
    tr[q].s += 1ll * v * nums[x];

    if (l == r) return q;

    int mid = l + r >> 1;
    if (x <= mid) {
        tr[q].l = insert(tr[q].l, l, mid, x, v);
    } else {
        tr[q].r = insert(tr[q].r, mid + 1, r, x, v);
    }

    tr[q].c = tr[tr[q].l].c + tr[tr[q].r].c;

    return q;
}

long long query(int u, int l, int r, int x) {
    if (l == r) return tr[u].s / tr[u].c * x;
    int mid = l + r >> 1;
    if (x <= tr[tr[u].l].c) return query(tr[u].l, l, mid, x);
    return query(tr[u].r, mid + 1, r, x - tr[tr[u].l].c) + tr[tr[u].l].s;
}
