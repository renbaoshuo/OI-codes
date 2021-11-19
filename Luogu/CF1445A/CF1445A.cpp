#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, a[55], b[55];
        bool flag = false;
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        reverse(b, b + n);
        for (int i = 0; i < n; i++) {
            if (a[i] + b[i] > x) {
                flag = true;
            }
        }
        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
