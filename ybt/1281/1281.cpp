#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, a[N], f[N], ans;

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
        ans = std::max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}
