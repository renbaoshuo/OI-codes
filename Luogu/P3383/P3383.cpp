#include <bits/stdc++.h>

using namespace std;

int n, q, k, p, primes[100000005];
bool not_prime[100000005];

int main() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) primes[++p] = i;
        for (int j = 1; primes[j] * i <= n; j++) {
            not_prime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    while (q--) {
        cin >> k;
        cout << primes[k] << endl;
    }
    return 0;
}
