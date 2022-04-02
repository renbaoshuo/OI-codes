#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, f[N], ans = std::numeric_limits<int>::min();

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        f[i] = std::max(f[i - 1] + x, x);
        ans = std::max(ans, f[i]);
    }
    cout << ans << endl;

    return 0;
}
