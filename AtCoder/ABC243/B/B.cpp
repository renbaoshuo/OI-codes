#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, a[N], b[N], ans1, ans2;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        ans1 += a[i] == b[i];
    }
    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j]) ans2++;
        }
    }
    cout << ans1 << endl
         << ans2 - ans1 << endl;
    return 0;
}
