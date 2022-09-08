#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, l, r, a[N << 1];
long long f[N << 1], ans = std::numeric_limits<int>::min();

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill_n(f + 1, (N << 1) - 1, std::numeric_limits<int>::min());

    cin >> n >> l >> r;

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = l; i < n + r; i++) {
        for (int j = std::max(i - r, 0); j <= i - l; j++) {
            f[i] = std::max(f[i], f[j] + a[i]);
        }
    }

    for (int i = n; i < n + r; i++) {
        ans = std::max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}
