#include <algorithm>
#include <iostream>

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

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j].second < a[i].second) f[i] = std::max(f[i], f[j] + 1);
        }
        ans = std::max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}
