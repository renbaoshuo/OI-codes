#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505,
          M = 6005;

int n, m, v[N], w[N], s[N], f[M], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= s[i]; k++) {
            for (int j = m; j >= v[i]; j--) {
                f[j] = std::max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        ans = std::max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}
