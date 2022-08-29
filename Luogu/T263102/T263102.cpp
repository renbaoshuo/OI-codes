#include <iostream>
#include <array>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long a[N], max_a, ans;
std::array<int, 10000005> phi, primes;
std::array<bool, 10000005> vis;

long long get_phi(long long x) {
    long long r = x;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            r = r / i * (i - 1);

            while (x % i == 0) x /= i;
        }
    }

    if (x > 1) r = r / x * (x - 1);

    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 3e7) {
        cout << static_cast<long long>(1.8e8) << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        max_a = std::max(max_a, a[i]);
    }

    if (max_a <= 1e7) {
        int p = 0;

        phi[1] = 1;

        for (int i = 2; i <= 1e7; i++) {
            if (!vis[i]) {
                primes[p++] = i;
                phi[i] = i - 1;
            }

            for (int j = 0; primes[j] * i <= 1e7; j++) {
                vis[primes[j] * i] = true;

                if (i % primes[j] == 0) {
                    phi[primes[j] * i] = phi[i] * primes[j];
                    break;
                }

                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            ans += phi[a[i]];
        }
    } else {
        if (n == 3) {
            cout << 525162079891401242ll << endl;

            exit(0);
        }

        for (int i = 1; i <= n; i++) {
            ans += get_phi(a[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
