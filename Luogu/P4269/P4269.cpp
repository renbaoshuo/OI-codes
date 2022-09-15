#include <iostream>
#include <algorithm>
#include <deque>
#include <functional>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int n, b;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;

    std::vector<int> a(n), d(n);

    for (int &x : a) cin >> x;

    std::vector<std::pair<int, int>> shoes;

    for (int i = 0, s; i < b; i++) {
        cin >> s >> d[i];

        shoes.emplace_back(i, s);
    }

    std::vector<int> ans(n);

    auto solve = [&](int ql, int qr, int l, int r, auto &&solve) -> void {
        if (ql > qr || l > r) return;

        if (l == r) {
            for (int i = ql; i <= qr; i++) {
                ans[shoes[i].first] = l;
            }

            return;
        }

        int mid = l + r >> 1;
        std::deque<int> q{0};
        std::vector<int> f(n);

        for (int i = 1; i < n; i++) {
            while (!q.empty() && i - q.front() > mid) q.pop_front();
            f[i] = std::max(a[i], f[q.front()]);
            while (!q.empty() && f[i] <= f[q.back()]) q.pop_back();
            q.push_back(i);
        }

        if (shoes[ql].second < *f.rbegin()) {
            solve(ql, qr, mid + 1, r, solve);
        } else if (shoes[qr].second >= *f.rbegin()) {
            solve(ql, qr, l, mid, solve);
        } else {
            int pos = std::lower_bound(
                          shoes.begin() + ql,
                          shoes.begin() + qr + 1,
                          std::make_pair(0, *f.rbegin()),
                          [](auto &&lhs, auto &&rhs) -> bool {
                              return lhs.second >= rhs.second;
                          })
                    - shoes.begin();

            solve(ql, pos - 1, l, mid, solve);
            solve(pos, qr, mid + 1, r, solve);
        }
    };

    std::sort(shoes.begin(), shoes.end(), [](auto &&lhs, auto &&rhs) -> bool {
        return lhs.second > rhs.second;
    });

    solve(0, b - 1, 1, n, solve);

    for (int i = 0; i < b; i++) {
        cout << (ans[i] <= d[i]) << endl;
    }

    return 0;
}
