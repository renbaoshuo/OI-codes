#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005];

int main() {
    cin >> t;
    while (t--) {
        bool flag = false;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 1; i < n; i++) {
            flag = flag || a[i] >= a[i + 1];
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
