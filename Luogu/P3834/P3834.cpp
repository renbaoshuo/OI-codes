#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, a[N];
int cnt, root[N];
std::vector<int> nums;

struct node {
    int l, r, c;
} tr[N << 5];

int find(int x) {
    return std::distance(nums.begin(), std::lower_bound(nums.begin(), nums.end(), x));
}

int build(int l, int r) {
    int p = ++cnt;

    if (l == r) return p;

    int mid = (l + r) >> 1;

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

    int mid = (l + r) >> 1;

    if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid + 1, r, x);

    tr[q].c = tr[tr[q].l].c + tr[tr[q].r].c;

    return q;
}

int query(int p, int q, int l, int r, int k) {
    if (l == r) return l;

    int mid = (l + r) >> 1;

    int c = tr[tr[q].l].c - tr[tr[p].l].c;

    if (c >= k) return query(tr[p].l, tr[q].l, l, mid, k);

    return query(tr[p].r, tr[q].r, mid + 1, r, k - c);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        nums.emplace_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    root[0] = build(0, nums.size() - 1);

    for (int i = 1; i <= n; i++) {
        root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
    }

    while (m--) {
        int l, r, k;

        cin >> l >> r >> k;

        cout << nums[query(root[l - 1], root[r], 0, nums.size() - 1, k)] << endl;
    }

    return 0;
}
