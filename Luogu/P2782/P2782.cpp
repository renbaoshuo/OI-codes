#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, f[N], ans;
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + n + 1);

    f[++ans] = a[1].second;
    for (int i = 2; i <= n; i++) {
        int k = std::upper_bound(f + 1, f + ans + 1, a[i].second) - f;
        f[k] = a[i].second;
        if (k > ans) ans++;
    }

    cout << ans << endl;

    return 0;
}
