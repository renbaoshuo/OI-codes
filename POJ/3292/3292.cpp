#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6;

int n, p, h_primes[N + 5], sum[N + 5];
bool not_h_prime[N + 5], is_h_semi_prime[N + 5];

int main() {
    std::ios::sync_with_stdio(false);

    for (int i = 5; i <= N; i += 4) {
        if (!not_h_prime[i]) {
            h_primes[++p] = i;
            for (int j = i * 5; j <= N; j += i * 4) {
                not_h_prime[j] = true;
            }
        }
    }

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= i && h_primes[i] * h_primes[j] <= N; j++) {
            is_h_semi_prime[h_primes[i] * h_primes[j]] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + is_h_semi_prime[i];
    }

    while (cin >> n, n) {
        cout << n << ' ' << sum[n] << endl;
    }

    return 0;
}
