#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, ans;
    cin >> n >> m;
    n++, m++;
    ans = n * m * (n * m - 1) * (n * m - 2) / 6 - n * m * (m - 1) * (m - 2) / 6 - m * n * (n - 1) * (n - 2) / 6;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= m; j++) {
            ans -= 2ll * (__gcd(i, j) - 1) * (n - i) * (m - j);
        }
    }
    cout << ans << endl;
    return 0;
}
