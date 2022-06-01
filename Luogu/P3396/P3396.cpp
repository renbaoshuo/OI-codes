#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1.5e5 + 5,
          NS = 505;

int n, m, t, a[N], f[NS][NS];
char op;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    t = std::ceil(std::sqrt(n));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            f[j][i % j] += a[i];
        }
    }

    for (int i = 1, x, y; i <= m; i++) {
        cin >> op >> x >> y;

        if (op == 'A') {
            if (x <= t) {
                cout << f[x][y % x] << endl;
            } else {
                int ans = 0;
                for (int i = y; i <= n; i += x) {
                    ans += a[i];
                }
                cout << ans << endl;
            }
        } else {  // op == 'C'
            for (int j = 1; j <= t; j++) {
                f[j][x % j] += (y - a[x]);
            }
            a[x] = y;
        }
    }

    return 0;
}
