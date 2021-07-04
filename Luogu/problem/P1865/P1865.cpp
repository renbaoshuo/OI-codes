#include <bits/stdc++.h>

using namespace std;

int ans[10000005];

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ans[i] = ans[i - 1];
        if (isPrime(i)) {
            ans[i]++;
        }
    }
    while (n--) {
        int l, r;
        cin >> l >> r;
        if (l > m || r > m || l < 1 || r < 1) {
            cout << "Crossing the line" << endl;
        }
        else {
            cout << ans[r] - ans[l - 1] << endl;
        }
    }
    return 0;
}
