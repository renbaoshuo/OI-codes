#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n, x, a[100005], b[100005], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i] -= x;
        if (a[i] < 0) {
            b[i] = -a[i];
            a[i] = 0;
        }
        if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];
        if (b[i] > b[i - 1]) ans += b[i] - b[i - 1];
    }
    cout << ans << endl;
    return 0;
}
