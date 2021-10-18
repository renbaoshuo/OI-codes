#include <bits/stdc++.h>

using namespace std;

int n, k, a[105];
bool flag;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cout << "? ";
        for (int j = 1; j < n; j++) {
            cout << i << ' ';
        }
        cout << n << endl;
        cin >> k;
        if (k != 0) {
            a[n] = i;
            a[k] = n;
            break;
        }
    }
    flag = !a[n];
    if (flag) a[n] = n;
    for (int p = 1; p < n; p++) {
        if (!flag && p == a[n]) continue;
        cout << "? ";
        for (int i = 1; i < n; i++) {
            cout << n - (flag ? 0 : p) << ' ';
        }
        cout << (flag ? p : n - a[n]) << endl;
        cin >> k;
        a[k] = p;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
