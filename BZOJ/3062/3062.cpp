#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, x[N], y[N];
long long ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    x[0] = m;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];

        ans += std::abs(x[i] - y[i]);
    }

    std::sort(x, x + 1 + n);
    std::sort(y, y + 1 + n);

    for (int i = 0; i <= n; i++) {
        ans += std::abs(x[i] - y[i]);
    }

    cout << ans << endl;

    return 0;
}
