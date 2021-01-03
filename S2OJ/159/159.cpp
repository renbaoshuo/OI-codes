#include <bits/stdc++.h>

using namespace std;

int n;
long long t, ans, p[60];

void insert(long long x) {
    for (int i = 50; i >= 0; i--) {
        if (x & (1ll << i)) {
            if (!p[i]) {
                p[i] = x;
                break;
            } else {
                x ^= p[i];
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        insert(t);
    }
    for (int i = 50; i >= 0; i--) {
        if ((ans ^ p[i]) > ans) {
            ans ^= p[i];
        }
    }
    cout << ans << endl;
    return 0;
}
