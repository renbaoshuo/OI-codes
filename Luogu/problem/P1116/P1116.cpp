// R38788162

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[10005], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] < a[j - 1]) {
                a[j] ^= a[j - 1];
                a[j - 1] ^= a[j];
                a[j] ^= a[j - 1];
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
