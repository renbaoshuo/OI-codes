#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x, y, z, k, ans = 0, a[10001];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        a[i] = k << 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        a[x] += z;
        a[y] += z;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i -= 2) {
        ans += a[i] - a[i - 1];
    }
    cout << ans / 2 << endl;
    return 0;
}
