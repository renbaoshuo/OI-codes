#include <iostream>
#include <cmath>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int t, p, primes[N];
bool not_prime[N];
std::unordered_map<long long, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < N; i++) {
        if (!not_prime[i]) primes[++p] = i;

        for (int j = 1; j <= p && primes[j] * i < N; j++) {
            not_prime[primes[j] * i] = true;

            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 1; i <= p; i++) {
        long long x = primes[i];
        map[x * x * x] = primes[i];
    }

    cin >> t;

    while (t--) {
        long long n, ans = 1;

        cin >> n;

        int m = std::sqrt(std::sqrt(n));

        if (map.count(n)) {
            cout << map[n] << endl;

            continue;
        }

        for (int i = 1, x = primes[i]; i <= p && x <= m && static_cast<long long>(x) * x * x <= n; x = primes[++i]) {
            long long y = static_cast<long long>(x) * x * x;

            while (n % y == 0) {
                ans *= x;
                n /= y;
            }

            while (n % x == 0) {
                n /= x;
            }
        }

        if (map.count(n)) ans *= map[n];

        cout << ans << endl;
    }

    return 0;
}
