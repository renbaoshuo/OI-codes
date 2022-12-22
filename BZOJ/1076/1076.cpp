#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15 + 2,
          K = 105;

int k, n, p[N], s[N];
double f[K][1 << N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> p[i];

        while (cin >> x, x) {
            s[i] |= 1 << x - 1;
        }
    }

    for (int i = k; i; i--) {
        for (int t = 0; t < 1 << n; t++) {
            for (int j = 1; j <= n; j++) {
                if ((t & s[j]) == s[j]) {
                    f[i][t] += std::max(f[i + 1][t], f[i + 1][t | (1 << j - 1)] + p[j]);
                } else {
                    f[i][t] += f[i + 1][t];
                }
            }

            f[i][t] /= n;
        }
    }

    cout << std::fixed << std::setprecision(6) << f[1][0] << endl;

    return 0;
}
