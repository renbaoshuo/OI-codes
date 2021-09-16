#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

int n, x;
long long ans = 1;

int main() {
    cin >> n;
    map<int, int> primes;
    while (n--) {
        cin >> x;
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        primes[x] += x > 1;
    }
    for (auto p : primes) {
        long long t = 1;
        while (p.second--) {
            t = (t * p.first + 1) % mod;
        }
        ans = ans * t % mod;
    }
    cout << ans << endl;
    return 0;
}
