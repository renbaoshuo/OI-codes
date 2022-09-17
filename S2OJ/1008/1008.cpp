#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, c[N], st[N];
long long ans;
std::vector<int> xs;
std::pair<int, int> p[N];

inline int lowbit(int x) {
    return x & -x;
}

void insert(int x, int y) {
    for (; x; x -= lowbit(x)) c[x] = std::min(c[x], y);
}

int query(int x) {
    int res = std::numeric_limits<int>::max();

    for (; x <= n; x += lowbit(x)) res = std::min(res, c[x]);

    return res;
}

void clear(int x) {
    for (; x; x -= lowbit(x)) c[x] = std::numeric_limits<int>::max();
}

int search(int l, int r, int y) {
    int res = r + 1;

    while (l <= r) {
        int mid = l + r >> 1;

        if (p[st[mid]].second < y) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

void solve(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);

    for (int i = l, j = mid + 1, top = 0; i <= mid; i++) {
        while (j <= r && p[j].second > p[i].second) {
            while (top && p[st[top]].first > p[j].first) top--;

            st[++top] = j++;
        }

        ans += top - search(1, top, query(p[i].first)) + 1;

        insert(p[i].first, p[i].second);
    }

    for (int i = l; i <= mid; i++) {
        clear(p[i].first);
    }

    std::sort(p + l, p + r + 1, [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    });
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill_n(c, N, std::numeric_limits<int>::max());

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;

        xs.emplace_back(p[i].first);
    }

    std::sort(p + 1, p + 1 + n, [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.first < b.first;
    });
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    for (int i = 1; i <= n; i++) {
        p[i].first = std::lower_bound(xs.begin(), xs.end(), p[i].first) - xs.begin() + 1;
    }

    solve(1, n);

    cout << ans << endl;

    return 0;
}
