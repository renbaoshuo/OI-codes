#include <bits/stdc++.h>

using namespace std;

int n, p, primes[1000005], phi[1000005];
bool vis[1000005];
long long ans;

void get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[p++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}

int main() {
    cin >> n;
    get_eulers(n);
    for (int i = 1; i <= n; i++) {
        ans += phi[i];
    }
    cout << ans << endl;
    return 0;
}
