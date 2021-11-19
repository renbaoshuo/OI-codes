#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long x, n, ans = 1;
    cin >> x >> n;
    for (unsigned long long i = 0; i < n; i++) {
        ans += ans * x;
    }
    cout << ans << endl;
    return 0;
}
