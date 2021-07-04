#include <bits/stdc++.h>

using namespace std;

long long a[50005];

int main() {
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        a[i] = a[i - 1] + k;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j + i <= n; j++) {
            if ((a[i + j] - a[j]) % 7 == 0) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
