#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int t, n, pos[200005];
std::pair<int, int> a[200005];

int main() {
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        std::sort(a + 1, a + 1 + n, std::greater<std::pair<int, int>>());
        for (int i = 1, j = 1, f = 1; i <= n; i++) {
            pos[a[i].second] = j * f;
            ans += j * 2ll * a[i].first;
            if (f == -1) j++;
            f = -f;
        }
        cout << ans << endl;
        for (int i = 0; i <= n; i++) {
            cout << pos[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
