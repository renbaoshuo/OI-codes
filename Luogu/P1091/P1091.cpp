#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, a[N], f[N], g[N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) f[i] = std::max(f[i], f[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) g[i] = std::max(g[i], g[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, f[i] + g[i] - 1);
    }

    cout << n - ans << endl;

    return 0;
}
