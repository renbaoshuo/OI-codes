#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e6 + 5;

int n, s_a, s_b, s_c, s_d, a[N], b[N], mod, ans;

inline int f(int x) {
    return (static_cast<long long>(s_a) % mod * x % mod * x % mod * x % mod
            + static_cast<long long>(s_b) % mod * x % mod * x % mod
            + static_cast<long long>(s_c) % mod * x % mod
            + s_d)
         % mod;
}

bool check(int x) {
    std::copy_n(a + 1, n, b + 1);

    for (int i = 1; i <= n; i++) {
        b[i] = std::max(b[i - 1], b[i] - x);

        if (std::abs(a[i] - b[i]) > x) return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s_a >> s_b >> s_c >> s_d >> a[1] >> mod;

    for (int i = 2; i <= n; i++) {
        a[i] = (f(a[i - 1]) + f(a[i - 2])) % mod;
    }

    int l = 0, r = mod;

    while (l <= r) {
        int mid = l + r >> 1;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
