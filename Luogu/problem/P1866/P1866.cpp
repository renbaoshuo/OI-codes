#include <bits/stdc++.h>

using namespace std;

int n, a[55];
long long ans = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        ans *= a[i] - i + 1;
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}
