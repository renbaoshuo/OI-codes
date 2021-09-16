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
        ans = ans * (p.second + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}
