#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 205;

int n, a[N], f[N], r[N], t, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) f[i] = std::max(f[i], f[j] + 1);
        }

        if (f[i] > ans) {
            ans = f[i];
            t = i;
        }
    }

    cout << "max=" << ans << endl;

    for (int i = t; i; i--) {
        if (f[i] == ans && a[i] <= a[t]) {
            f[i] = 0;
            ans--;
            t = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!f[i]) cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}
