#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

struct node {
    int l, r, m, d;

    node(int _l = 0, int _r = 0)
        : l(_l), r(_r), m(0), d(0) {}
} tr[N << 3];

void pushup(int u) {
    tr[u].m = std::max(tr[u << 1].m, tr[u << 1 | 1].m);
}

void pushdown(int u) {
    if (!tr[u].d) return;

    tr[u << 1].d += tr[u].d;
    tr[u << 1 | 1].d += tr[u].d;

    tr[u << 1].m += tr[u].d;
    tr[u << 1 | 1].m += tr[u].d;

    tr[u].d = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].d += v;
        tr[u].m += v;

        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, v);
    if (r > mid) modify(u << 1 | 1, l, r, v);

    pushup(u);
}

int n, m, ans = std::numeric_limits<int>::max();
std::pair<int, int> seg[N];
std::vector<int> nums;

int len(int p) {
    return nums[seg[p].second - 1] - nums[seg[p].first - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> seg[i].first >> seg[i].second;

        nums.emplace_back(seg[i].first);
        nums.emplace_back(seg[i].second);
    }

    std::sort(seg + 1, seg + 1 + n, [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second - a.first < b.second - b.first;
    });

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    for (int i = 1; i <= n; i++) {
        seg[i].first = std::lower_bound(nums.begin(), nums.end(), seg[i].first) - nums.begin() + 1;
        seg[i].second = std::lower_bound(nums.begin(), nums.end(), seg[i].second) - nums.begin() + 1;
    }

    build(1, 1, nums.size());

    for (int i = 1, l = 1; i <= n; i++) {
        modify(1, seg[i].first, seg[i].second, 1);

        while (tr[1].m >= m) {
            ans = std::min(ans, len(i) - len(l));
            modify(1, seg[l].first, seg[l].second, -1);
            l++;
        }
    }

    cout << (ans == std::numeric_limits<int>::max() ? -1 : ans) << endl;

    return 0;
}
