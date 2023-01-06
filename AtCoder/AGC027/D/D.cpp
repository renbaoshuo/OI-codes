#include <iostream>
#include <algorithm>
#include <experimental/numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505,
          M = 10005;

int n;
long long a[N][N];
int p, primes[M];
bool not_prime[M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    not_prime[1] = true;

    for (int i = 2; i <= 10000; i++) {
        if (!not_prime[i]) primes[++p] = i;

        for (int j = 1; j <= p && i * primes[j] <= 10000; j++) {
            not_prime[i * primes[j]] = true;

            if (i % primes[j] == 0) break;
        }
    }

    cin >> n;

    if (n == 2) {
        cout << 4 << ' ' << 7 << endl
             << 23 << ' ' << 10 << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = (i + 1 & 1) + 1; j <= n; j += 2) {
            a[i][j] = static_cast<long long>(primes[(i + j) / 2]) * primes[n + (i - j) / 2 + (n + 1) / 2];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = (i & 1) + 1; j <= n; j += 2) {
            a[i][j] = std::experimental::lcm(
                          std::experimental::lcm(std::max(1ll, a[i - 1][j]), std::max(1ll, a[i][j - 1])),
                          std::experimental::lcm(std::max(1ll, a[i][j + 1]), std::max(1ll, a[i + 1][j])))
                    + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}
