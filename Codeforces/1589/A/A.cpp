#include <bits/stdc++.h>

using namespace std;

int t, u, v;
long long uu, vv, k, x, y;

int main() {
    cin >> t;
    while (t--) {
        cin >> u >> v;
        uu = 1ll * u * u;
        vv = 1ll * v * v;
        k = __gcd(uu, vv);
        x = -(uu / k);
        y = vv / k;
        cout << x << ' ' << y << endl;
    }
    return 0;
}
