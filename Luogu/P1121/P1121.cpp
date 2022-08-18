#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N];
bool flag = true;
long long sum, s_max[N], s_min[N], f_max[N], f_min[N], g_max[N], g_min[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        sum += a[i];
        flag &= a[i] < 0;
    }

    if (flag) {
        std::sort(a + 1, a + 1 + n);

        cout << a[n] + a[n - 1] << endl;

        exit(0);
    }

    ans = std::numeric_limits<int>::min();
    std::fill_n(s_max, N, std::numeric_limits<int>::min());
    std::fill_n(s_min, N, std::numeric_limits<int>::max());
    std::fill_n(f_max, N, std::numeric_limits<int>::min());
    std::fill_n(f_min, N, std::numeric_limits<int>::max());
    std::fill_n(g_max, N, std::numeric_limits<int>::min());
    std::fill_n(g_min, N, std::numeric_limits<int>::max());

    for (int i = 1; i <= n; i++) {
        s_max[i] = std::max(s_max[i - 1] + a[i], static_cast<long long>(a[i]));
        s_min[i] = std::min(s_min[i - 1] + a[i], static_cast<long long>(a[i]));

        f_max[i] = std::max(f_max[i - 1], s_max[i]);
        f_min[i] = std::min(f_min[i - 1], s_min[i]);
    }

    std::fill_n(s_max, N, std::numeric_limits<int>::min());
    std::fill_n(s_min, N, std::numeric_limits<int>::max());

    for (int i = n; i; i--) {
        s_max[i] = std::max(s_max[i + 1] + a[i], static_cast<long long>(a[i]));
        s_min[i] = std::min(s_min[i + 1] + a[i], static_cast<long long>(a[i]));

        g_max[i] = std::max(g_max[i + 1], s_min[i]);
        g_min[i] = std::min(g_min[i + 1], s_min[i]);
    }

    std::cerr << ans << endl;

    // 不跨环
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, f_max[i] + g_max[i + 1]);
    }

    std::cerr << ans << endl;

    // 跨环
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, sum - (f_min[i] + g_min[i + 1]));
    }

    cout << ans << endl;

    return 0;
}
