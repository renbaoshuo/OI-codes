#include <bits/stdc++.h>

using namespace std;

int n, ans, a[1000005], f[1000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            f[i] = f[i - 1] + 1;
        } else {
            f[i] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ++ans << endl;
    return 0;
}
