#include <bits/stdc++.h>

using namespace std;

long long n, a[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 2; i--) {
        if (abs(a[i - 1] - a[i]) > abs(a[i - 1] + a[i])) {
            a[i - 1] -= a[i];
        } else {
            a[i - 1] += a[i];
        }
    }
    cout << max(a[1] - a[2], a[1] + a[2]) << endl;
    return 0;
}
