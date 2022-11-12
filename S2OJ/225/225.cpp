#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const double eps = 1e-7;

int n, k, a[N], b[N];
double c[N];

inline bool check(double mid) {
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        c[i] = static_cast<double>(a[i]) - mid * b[i];
    }

    std::sort(c + 1, c + 1 + n, std::greater<>());

    for (int i = 1; i <= k; i++) {
        sum += c[i];
    }

    return sum >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    double l = 0, r = 1e9;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << std::fixed << std::setprecision(4) << l << endl;

    return 0;
}
