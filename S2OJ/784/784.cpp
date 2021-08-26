#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int n, m, z, x[100005], y[100005];
long long ans, mx, my, az;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> z;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z;
        az += z;
    }
    sort(x + 1, x + 1 + m);
    sort(y + 1, y + 1 + m);
    mx = x[m + 1 >> 1];
    my = y[m + 1 >> 1];
    for (int i = 1; i <= m; i++) {
        ans += abs(x[i] - mx) + abs(y[i] - my);
    }
    cout << ans + az << endl;
    cout << mx << ' ' << my << endl;
    return 0;
}
