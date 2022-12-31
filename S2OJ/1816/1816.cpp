#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N], s[N];
double ans;

double calc(int pos, int len) {
    return static_cast<double>(s[n] - s[n - len] + s[pos] - s[pos - len - 1]) / (len * 2 + 1);
}

int solve(int x) {
    int l = 1,
        r = std::min(x - 1, n - x),
        res = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (calc(x, mid - 1) <= calc(x, mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    std::copy_n(std::istream_iterator<int>(cin), n, a + 1);
    std::sort(a + 1, a + 1 + n);
    std::partial_sum(a + 1, a + 1 + n, s + 1);

    for (int i = 2; i < n; i++) {
        ans = std::max(ans, calc(i, solve(i)) - a[i]);
    }

    cout << std::fixed << std::setprecision(5) << ans << endl;

    return 0;
}
