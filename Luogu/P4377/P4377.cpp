#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 255,
          W = 1005;
const double eps = 1e-6;

int n, w, a[N], b[N];
double f[W];

bool check(double x) {
    std::fill_n(f + 1, w, -1e9);

    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            int k = std::min(w, j + a[i]);

            f[k] = std::max(f[k], f[j] + b[i] - x * a[i]);
        }
    }

    return f[w] >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    double l = 0,
           r = 1e6;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << static_cast<int>(std::floor(l * 1000)) << endl;

    return 0;
}
