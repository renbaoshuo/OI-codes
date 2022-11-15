#include <iostream>
#include <cmath>
#include <cstring>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25;

int n, f[1 << N], g[1 << N];
std::pair<int, int> a[N];

int dis(int u, int v) {
    return std::pow(a[u].first - a[v].first, 2) + std::pow(a[u].second - a[v].second, 2);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a[0].first >> a[0].second >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;

    for (int s = 1; s < 1 << n; s++) {
        int i = __builtin_ffs(s) - 1;

        for (int t = s; t; t ^= (t & -t)) {
            int j = __builtin_ffs(t) - 1;
            int w = f[s ^ ((1 << i) | (1 << j))] + dis(0, i + 1) + dis(i + 1, j + 1) + dis(j + 1, 0);

            if (w < f[s]) {
                f[s] = w;
                g[s] = s ^ ((1 << i) | (1 << j));
            }
        }
    }

    int s = (1 << n) - 1;

    cout << f[s] << endl;

    while (s) {
        int t = s ^ g[s];
        int a = __builtin_ffs(t & -t) - 1,
            b = __builtin_ffs(t ^ (1 << a)) - 1;

        if (~b) {
            cout << 0 << ' ' << a + 1 << ' ' << b + 1 << ' ';
        } else {
            cout << 0 << ' ' << a + 1 << ' ';
        }

        s = g[s];
    }

    cout << 0 << endl;

    return 0;
}
