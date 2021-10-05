#include <bits/stdc++.h>

using namespace std;

int n, p, ans, mu[40005], primes[40005];
bool vis[40005];

int main() {
    cin >> n;
    if (!--n) {
        cout << 0 << endl;
        exit(0);
    }
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++p] = i;
            mu[i] = -1;
        }
        for (int j = 1; i * primes[j] <= n; j++) {
            vis[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
            mu[i * primes[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += mu[i] * pow(n / i, 2);
    }
    cout << ans + 2 << endl;
    return 0;
}
