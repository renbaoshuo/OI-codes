#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, k, t, f[N][25];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> f[i][0];
    }

    t = std::__lg(n);
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            f[j][i] = std::max(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
        }
    }

    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;

        k = std::__lg(r - l + 1);

        cout << std::max(f[l][k], f[r - (1 << k) + 1][k]) << endl;
    }

    return 0;
}
