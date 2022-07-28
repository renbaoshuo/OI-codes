#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N];
long long lst, sum, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 0; i <= n; i++) {
        sum += a[i];
        while (a[i] == a[i + 1]) sum += a[++i];
        ans += sum - std::max(lst, (static_cast<long long>(a[i]) + 1 >> 1) - 1);
        lst = sum;
    }

    cout << ans << endl;

    return 0;
}
