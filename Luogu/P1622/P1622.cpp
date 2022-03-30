#include <algorithm>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int p, q, a[N], f[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> p >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + q);
    a[q + 1] = p + 1;
    for (int l = 1; l <= q; l++) {
        for (int i = 1, j = i + l - 1; j <= q; i++, j++) {
            f[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k <= j; k++) {
                f[i][j] = std::min(f[i][j], f[i][k - 1] + f[k + 1][j] + a[j + 1] - a[i - 1] - 2);
            }
        }
    }

    cout << f[1][q] << endl;

    return 0;
}
