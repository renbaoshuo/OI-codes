#include <bits/stdc++.h>

using namespace std;

int t, n, a[105], b[105];

int main() {
    cin >> t;
    while (t--) {
        bool flag = true;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++) {
            if (b[i] - a[i] > 1 || b[i] - a[i] < 0) flag = false;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
