#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int t, l, r, a, b, c, ans;
int p, cnt, primes[10000005], sum[10000005];
bool not_prime[10000005];

inline bool check(int x) {
    int sum = 0;

    while (x) {
        sum += x % 10;
        x /= 10;
    }

    return !not_prime[sum];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= 10000000; i++) {
        if (!not_prime[i]) primes[++p] = i;

        for (int j = 1; j <= p && primes[j] * i <= 10000000; j++) {
            not_prime[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 1; i <= 10000000; i++) {
        if (!not_prime[i] && check(i)) sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1];
    }

    cin >> t >> l >> r >> a >> b >> c;

    while (t--) {
        ans ^= sum[r] - sum[l - 1];

        l = ((l ^ b) + a) % c + 1;
        r = ((r ^ b) + a) % c + 1;
        if (l > r) std::swap(l, r);
    }

    cout << ans << endl;

    return 0;
}
