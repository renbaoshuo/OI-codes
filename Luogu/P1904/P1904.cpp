#include <bits/stdc++.h>

using namespace std;

int l, h, r, ml, mr, a[10005];

int main() {
    while (cin >> l >> h >> r) {
        ml = min(ml, l);
        mr = max(mr, r);
        for (int i = l; i < r; i++) {
            a[i] = max(a[i], h);
        }
    }
    for (int i = ml - 1; i <= mr; i++) {
        if (a[i] != a[i - 1]) {
            cout << i << ' ' << a[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}
