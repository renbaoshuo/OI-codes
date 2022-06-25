#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, w[N], a[N], x[N], y[N], ans;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];

        a[i] = w[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        w[i] = std::lower_bound(a + 1, a + 1 + n, w[i]) - a;
    }

    for (int i = 1; i <= n; i++) {
        (s[i] == '0' ? x : y)[w[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }

    for (int i = 1; i <= n + 1; i++) {
        ans = std::max(ans, x[i - 1] + y[n] - y[i - 1]);
    }

    cout << ans << endl;

    return 0;
}
