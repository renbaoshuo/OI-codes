#include <bits/stdc++.h>

using namespace std;

long long t, n, m, k;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        k -= 2;
        if (n == 1) {
            cout << (m == 0 && k >= 0 ? "YES" : "NO") << endl;
        } else {
            cout << ((m < n - 1 || n * (n - 1) < m * 2 || (n * (n - 1) == m * 2 && k < 1) || (n * (n - 1) > m * 2 && k < 2)) ? "NO" : "YES") << endl;
        }
    }
    return 0;
}
