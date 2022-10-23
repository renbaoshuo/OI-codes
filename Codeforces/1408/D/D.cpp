#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005,
          M = 1e6 + 5;

int n, m, a[N], b[N], c[N], d[N], f[M], max, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[j] < b[i]) continue;
            max = std::max(max, d[j] - b[i]);
            f[d[j] - b[i]] = std::max(f[d[j] - b[i]], c[j] - a[i] + 1);
        }
    }

    ans = max + 1;
    for (int i = ::max, max = 0; i >= 0; i--) {
        max = std::max(max, f[i]);
        ans = std::min(ans, i + max);
    }

    cout << ans << endl;

    return 0;
}
