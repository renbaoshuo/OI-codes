#include <iostream>
#include <algorithm>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, a[N], cnt, ans;
long long sum;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << 0 << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 1, p = 1; i <= n; i++) {
        sum += a[i];

        while (p <= i && a[p] <= sum / i) p++;

        ans = std::max(ans, i - p + 1);
    }

    cout << ans << endl;

    return 0;
}
