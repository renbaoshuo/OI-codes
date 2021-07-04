#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, v, a, ans = 0;
    cin >> n >> v >> m >> a;
    for (int i = 1; i <= n; i++) {
        ans += v;
        if (i % m == 0) v += a;
    }
    cout << ans << endl;
    return 0;
}
