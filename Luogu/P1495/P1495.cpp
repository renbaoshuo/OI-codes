#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long a[N], b[N];

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

    for (int i = 1; i <= n; i++) {
        mod *= a[i];
    }

    for (int i = 1; i <= n; i++) {
        long long m = mod / a[i], x, y;
        exgcd(m, a[i], x, y);
        ans = (ans + b[i] * m * x % mod) % mod;
    }

    return (ans % mod + mod) % mod;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    cout << CRT() << endl;

    return 0;
}
