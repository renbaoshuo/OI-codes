#include <bits/stdc++.h>

using namespace std;

bool isprime[1000005];
int n, ans;

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        isprime[i] = true;
    }
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isprime[i] && 1ll * i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += isprime[i];
    }
    cout << ans;
    return 0;
}
