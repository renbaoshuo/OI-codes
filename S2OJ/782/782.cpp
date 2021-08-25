#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

long long n, ans[10000005];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i) continue;
        if ((i & 1ll) && i != 1) ans[++ans[0]] = n / i * (i - 1);
        if (((n / i) & 1ll) && n / i != 1) ans[++ans[0]] = i * (n / i - 1);
    }
    sort(ans + 1, ans + 1 + ans[0]);
    for (int i = 0; i <= ans[0]; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
