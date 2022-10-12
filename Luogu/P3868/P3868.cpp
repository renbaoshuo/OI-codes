#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int K = 15;

int k;
long long a[K], b[K];

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return g;
}

long long CRT() {
    long long mod = 1, ans = 0;

    for (int i = 1; i <= k; i++) {
        mod *= b[i];
    }

    for (int i = 1; i <= k; i++) {
        long long m = mod / b[i], x, y;
        exgcd(m, b[i], x, y);
        ans = (ans + static_cast<__int128>(a[i]) * m * x % mod) % mod;
    }

    return (ans % mod + mod) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> b[i];

        a[i] = (a[i] % b[i] + b[i]) % b[i];
    }

    cout << CRT() << endl;

    return 0;
}
