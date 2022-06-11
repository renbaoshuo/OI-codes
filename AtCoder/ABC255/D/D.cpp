#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, q, x, a[N];
long long s[N], s2[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    while (q--) {
        cin >> x;

        if (x <= a[1] || x >= a[n]) {
            cout << std::abs(s[n] - 1ll * x * n) << endl;
        } else {
            int p = std::lower_bound(a + 1, a + 1 + n, x) - a - 1;

            cout << (1ll * x * p - s[p]) + (s[n] - s[p] - 1ll * x * (n - p)) << endl;
        }
    }

    return 0;
}
