#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 200005;

int n, a[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    std::sort(a + 1, a + 1 + n);
    n = std::unique(a + 1, a + 1 + n) - a - 1;
    a[n + 1] = std::numeric_limits<int>::max();
    for (int i = 1; i <= n; i++) {
        for (int j = 2; (j - 1) * a[i] <= a[n]; j++) {
            ans = std::max(ans, *(std::lower_bound(a + 1, a + 1 + n + 1, j * a[i]) - 1) % a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
