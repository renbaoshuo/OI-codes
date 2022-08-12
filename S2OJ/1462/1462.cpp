#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int t, n, a[N], d[N], cnt[N], f[N][35], g[N];

int calc(int l, int r) {
    if (d[l] == 0) return 1;

    std::for_each(f + l, f + r + 1, [](int *it) { std::fill_n(it, 35, -1); });
    f[l][cnt[l]] = l - 1;

    for (int i = l + 1; i <= r; i++) {
        f[i][cnt[i]] = i - 1;

        for (int j = cnt[i] + 1; j <= 32; j++) {
            if (f[f[i][j - 1]][j - 1] == -1) break;

            f[i][j] = f[f[i][j - 1]][j - 1];

            if (f[i][j] < l) break;
        }
    }

    std::fill(g + l, g + r + 1, std::numeric_limits<int>::max());
    g[l - 1] = 0;

    for (int i = l; i <= r; i++) {
        for (int j = 0; j <= 32; j++) {
            if (~f[i][j]) {
                g[i] = std::min(g[i], g[f[i][j]] + 1);
            }
        }
    }

    return g[r];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++) {
            d[i] = a[i + 1] - a[i];
        }

        for (int i = 1; i < n; i++) {
            cnt[i] = 0;

            while (d[i] && !(d[i] & 1)) {
                cnt[i]++;
                d[i] >>= 1;
            }
        }

        int lst = 1, ans = 0;

        for (int i = 1; i < n - 1; i++) {
            if (d[i] != d[i + 1]) {
                ans += calc(lst, i);
                lst = i + 1;
            }
        }

        ans += calc(lst, n - 1);

        cout << ans + 1 << endl;
    }

    return 0;
}
