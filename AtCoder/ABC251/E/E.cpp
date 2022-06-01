#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n;
long long a[N], f[N][2], g[N][2];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof(g));

    f[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i - 1][1];
        f[i][1] = std::min({f[i][1], f[i - 1][0] + a[i], f[i - 1][1] + a[i]});
    }

    g[1][0] = a[n];
    for (int i = 2; i < n; i++) {
        g[i][0] = g[i - 1][1];
        g[i][1] = std::min({g[i][1], g[i - 1][0] + a[i], g[i - 1][1] + a[i]});
    }

    cout << std::min({f[n][0], f[n][1], g[n - 1][0], g[n - 1][1]}) << endl;

    return 0;
}
