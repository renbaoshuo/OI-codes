#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, t, a[N], st[N], ed[N], pos[N], f[1005][1005], cnt[N];
std::vector<int> nums, v[N];

inline int find(int x) {
    return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

void pre(int x) {
    memset(cnt, 0x00, sizeof(cnt));
    std::pair<int, int> res;

    for (int i = st[x]; i <= n; i++) {
        cnt[a[i]]++;

        if (cnt[a[i]] > res.first || (cnt[a[i]] == res.first && nums[a[i]] < nums[res.second])) {
            res = std::make_pair(cnt[a[i]], a[i]);
        }

        f[x][pos[i]] = res.second;
    }
}

inline int get(int x, int l, int r) {
    return std::upper_bound(v[x].begin(), v[x].end(), r) - std::lower_bound(v[x].begin(), v[x].end(), l);
}

int query(int l, int r) {
    int p = pos[l],
        q = pos[r];
    std::pair<int, int> res;

    if (p == q) {
        for (int i = l; i <= r; i++) {
            int _ = get(a[i], l, r);
            if (_ > res.first || (_ == res.first && nums[a[i]] < nums[res.second])) {
                res = std::make_pair(_, a[i]);
            }
        }

        return nums[res.second];
    }

    res.second = f[p + 1][q - 1];
    res.first = get(res.second, l, r);

    for (int i = l; i <= ed[p]; i++) {
        int _ = get(a[i], l, r);
        if (_ > res.first || (_ == res.first && nums[a[i]] < nums[res.second])) {
            res = std::make_pair(_, a[i]);
        }
    }
    for (int i = st[q]; i <= r; i++) {
        int _ = get(a[i], l, r);
        if (_ > res.first || (_ == res.first && nums[a[i]] < nums[res.second])) {
            res = std::make_pair(_, a[i]);
        }
    }

    return nums[res.second];
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    t = std::sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[i] = (i - 1) / t + 1;
        nums.push_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    nums.insert(nums.begin(), 0);

    for (int i = 1; i <= n; i++) v[a[i] = find(a[i])].push_back(i);

    for (int i = 1; i <= pos[n]; i++) {
        st[i] = (i - 1) * t + 1;
        ed[i] = std::min(n, i * t);
    }

    for (int i = 1; i <= pos[n]; i++) pre(i);

    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}
