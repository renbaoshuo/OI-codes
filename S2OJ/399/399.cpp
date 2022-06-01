#include <iostream>
#include <algorithm>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long sum[N], ans = std::numeric_limits<int>::min();
std::pair<int, int> a[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    std::sort(a + 1, a + 1 + n, [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
        return a.first + a.second < b.first + b.second;
    });

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].first;
        ans = std::max(ans, sum[i - 1] - a[i].second);
    }

    cout << ans << endl;

    return 0;
}
