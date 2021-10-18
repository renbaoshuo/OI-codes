#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int t, inv[100005];
long long n, ans;

int main() {
    cin >> t;
    while (t--) {
        ans = 1;
        cin >> n;
        n *= 2;
        while (n) {
            ans = ans * n-- % mod;
        }
        cout << ans * 500000004 % mod << endl;
    }
    return 0;
}
