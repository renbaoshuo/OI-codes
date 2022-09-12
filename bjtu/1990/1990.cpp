#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N], b[N], s1[N], s2[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (a[i] == b[i]);
        s2[i] = s2[i - 1] + (a[i] == b[i - 1]);
    }

    ans = s2[n];
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, s1[i - 1] + s2[n] - s2[i] + (a[i] == b[n]));
    }

    cout << ans << endl;

    return 0;
}
