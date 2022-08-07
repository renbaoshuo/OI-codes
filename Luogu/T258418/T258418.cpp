#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, a[N], ans = 1;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int min = *std::min_element(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        ans = (static_cast<long long>(ans) * static_cast<long long>(std::floor(static_cast<double>(a[i]) / min))) % mod;
    }

    cout << min << ' ' << ans << endl;

    return 0;
}
