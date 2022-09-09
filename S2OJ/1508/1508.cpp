#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

long long k, _k, cnt, p[N], c[N], ans = 1;
bool flag;

long long binpow(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    _k = k;

    for (long long i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            p[++cnt] = i;

            while (k % i == 0) {
                k /= i;
                c[cnt]++;
            }
        }
    }

    if (k) {
        p[++cnt] = k;
        c[cnt] = 1;
    }

    for (int i = 1; i <= cnt; i++) {
        ans *= binpow(p[i], static_cast<long long>(std::ceil(static_cast<long double>(c[i]) / 2)));
    }

    cout << (ans % _k ? ans : -1) << endl;

    return 0;
}
