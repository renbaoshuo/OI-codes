#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, k, a[N], b[N], f[N][2];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] |= ((std::abs(a[i] - a[i - 1]) <= k && f[i - 1][0]) || (std::abs(a[i] - b[i - 1]) <= k && f[i - 1][1]));
        f[i][1] |= ((std::abs(b[i] - a[i - 1]) <= k && f[i - 1][0]) || (std::abs(b[i] - b[i - 1]) <= k && f[i - 1][1]));
    }

    if (f[n][0] | f[n][1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
