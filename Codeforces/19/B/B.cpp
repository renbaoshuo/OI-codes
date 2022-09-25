#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n, t[N], c[N];
long long f[N << 1], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        t[i] = std::min(n, t[i] + 1);
    }

    ans = 0x3f3f3f3f3f3f3f3f;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = n << 1; j >= t[i]; j--) {
            f[j] = std::min(f[j], f[j - t[i]] + c[i]);
        }
    }

    for (int i = 0; i <= n; i++) {
        ans = std::min(ans, f[n + i]);
    }

    cout << ans << endl;

    return 0;
}
