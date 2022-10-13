#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25;

int n, a[N], p[N], d[N], m[N];

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        p[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = p[i - 1]; j != p[i]; j = j == n ? 1 : j + 1) {
            if (a[j] > i) d[i]++;
        }

        m[i] = n - i + 1;
        d[i] = (d[i] + 1) % m[i];
    }

    long long res = d[1], lcm = m[1];
    for (int i = 2; i <= n; i++) {
        long long x, y,
            g = exgcd(lcm, m[i], x, y),
            c = ((d[i] - res) % m[i] + m[i]) % m[i],
            m1 = m[i] / g,
            m2 = lcm / g * m[i];

        if (c % g) {
            cout << "NIE" << endl;

            exit(0);
        }

        x = (x % m[i] + m[i]) % m[i];
        x = (x * c / g % m1 + m1) % m1;
        res = ((lcm * x + res) % m2 + m2) % m2;
        lcm = m2;
    }

    cout << (res ? res : lcm) << endl;

    return 0;
}
