#include <iostream>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, a[N], b[N];
long long ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    std::sort(a + 1, a + 1 + n, std::greater<>());
    std::sort(b + 1, b + 1 + m, std::greater<>());

    int i = 1;

    for (; i <= n && a[i] >= 0 && b[i] >= 0; i++) {
        ans += static_cast<long long>(a[i]) * b[i];
    }

    std::sort(a + i, a + 1 + n);
    std::sort(b + i, b + 1 + m);

    for (; i <= n && a[i] < 0 && b[i] < 0; i++) {
        ans += static_cast<long long>(a[i]) * b[i];
    }

    std::sort(a + i, a + 1 + n, std::greater<>());
    std::sort(b + i, b + 1 + m, std::greater<>());

    for (; i <= n; i++) {
        ans += static_cast<long long>(a[i]) * b[i];
    }

    cout << ans << endl;

    return 0;
}
