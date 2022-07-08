#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;
const double eps = 1e-10;

int n, c, k, a[N];

bool check(double x) {
    int t = std::lower_bound(a + 1, a + 1 + n, static_cast<int>(x), std::greater<int>()) - a;

    if (n + c - (n - t + 1) < k) return false;  // 最坏情况时无法满足要求

    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        cnt += a[i] / x;  // 能拆成几个满足要求的
    }

    return cnt >= k;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n, std::greater<int>());

    double l = 0, r = 1e9;
    for (int i = 0; i < 1000; i++) {
        double mid = (l + r) / 2;

        (check(mid) ? l : r) = mid;
    }

    cout << std::fixed << std::setprecision(12) << l << endl;

    return 0;
}
