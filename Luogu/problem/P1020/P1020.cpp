#include <bits/stdc++.h>

using namespace std;

int n, l1, l2, a[100005], d1[100005], d2[100005];

int main() {
    while (cin >> a[++n]);
    n--;
    d1[++l1] = d2[++l2] = a[1];
    for (int i = 2; i <= n; i++) {
        if (d1[l1] >= a[i]) {
            d1[++l1] = a[i];
        }
        else {
            int* it = upper_bound(d1 + 1, d1 + 1 + l1, a[i], greater<int>());
            *it = a[i];
        }
        if (d2[l2] < a[i]) {
            d2[++l2] = a[i];
        }
        else {
            int* it = lower_bound(d2 + 1, d2 + 1 + l2, a[i], less<int>());
            *it = a[i];
        }
    }
    cout << l1 << endl << l2 << endl;
    return 0;
}
