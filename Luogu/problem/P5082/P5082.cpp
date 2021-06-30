#include <bits/stdc++.h>

using namespace std;

long long n, a[10000005], b[10000005], c[10000005], a1, b1, c1;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a1 += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
        b1 += b[i];
        c1 += c[i];
    }
    cout << fixed << setprecision(6) << 1.00 * (a1 * 3 - b1 * 2) / c1 << endl;
    return 0;
}
