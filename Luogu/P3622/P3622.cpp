#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int N = 1e4 + 5,
          C = 5e4 + 5,
          M = (1 << 5) + 5;

int n, c, a[C][M], f[N][M], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;

    for (int i = 1, e, f, l; i <= c; i++) {
        cin >> e >> f >> l;

        int fear = 0;

        for (int j = 1, x; j <= f; j++) {
            cin >> x;

            fear |= (1 << (x - e + n) % n);
        }

        int like = 0;

        for (int j = 1, y; j <= l; j++) {
            cin >> y;

            like |= (1 << (y - e + n) % n);
        }

        for (int j = 0; j < 1 << 5; j++) {
            if ((like & j) || (fear & ~j)) a[e][j]++;
        }
    }

    for (int s = 0; s < 1 << 5; s++) {
        std::fill_n(f[0], M, std::numeric_limits<int>::min());
        f[0][s] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 1 << 5; j++) {
                f[i][j] = max(f[i - 1][(j & 0b1111) << 1], f[i - 1][(j & 0b1111) << 1 | 1]) + a[i][j];
            }
        }

        ans = std::max(ans, f[n][s]);
    }

    cout << ans << endl;

    return 0;
}
