#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], sum[N];
double ans_a, ans_b;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n, std::greater<int>());

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    ans_a = 100.0 * 1 / n;
    ans_b = 1.0 * sum[1] * 100 / sum[n];

    for (int i = 2; i <= n; i++) {
        if (1.0 * sum[i] * 100 / sum[n] - 100.0 * i / n >= ans_b - ans_a) {
            ans_a = 100.0 * i / n;
            ans_b = 1.0 * sum[i] * 100 / sum[n];
        }
    }

    cout << std::fixed << std::setprecision(2) << ans_a << ' '
         << std::fixed << std::setprecision(2) << ans_b << endl;

    return 0;
}
