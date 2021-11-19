#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[5], t, o;
    cin >> n >> a[0] >> a[1] >> a[2];
    o = (a[0] % 2 + a[1] % 2 + a[2] % 2) / 2;
    for (int i = 0; i < n; i++) {
        if (i >= 3) {
            cin >> t;
        } else {
            t = a[i];
        }
        if (t % 2 != o) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}
