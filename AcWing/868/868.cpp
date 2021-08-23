#include <bits/stdc++.h>

using namespace std;

int n, p, primes[1000005];
bool not_prime[1000005];

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            primes[p++] = i;
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            not_prime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    cout << p << endl;
    return 0;
}
