#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int q, p, primes[N], sig[N], miu[N], phi[N];
bool is_prime[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ======

    phi[1] = miu[1] = sig[1] = 1;

    for (int i = 2; i < N; i++) {
        if (!is_prime[i]) {
            primes[++p] = i;

            phi[i] = i - 1;
            miu[i] = -1;
            sig[i] = i + 1;
        }

        for (int j = 1; j <= p && primes[j] * i < N; j++) {
            is_prime[i * primes[j]] = 1;

            miu[i * primes[j]] = -miu[i];
            phi[i * primes[j]] = phi[i] * phi[primes[j]];
            sig[i * primes[j]] = sig[i] * sig[primes[j]];

            if (i % primes[j] == 0) {
                miu[i * primes[j]] = 0;
                phi[i * primes[j]] = phi[i] * primes[j];
                sig[i * primes[j]] -= sig[i / primes[j]] * primes[j];

                break;
            }
        }
    }

    // ======

    cin >> q;

    while (q--) {
        int op, k;

        cin >> op >> k;

        if (op == 1) {
            cout << primes[k] << endl;
        } else {  // op == 2
            cout << sig[k] << ' ' << miu[k] << ' ' << phi[k] << endl;
        }
    }

    return 0;
}
