#include <bits/stdc++.h>

using namespace std;

long long n, m, t, ans, x;

long long gcd(long long a, long long b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    cin >> n >> m >> t;
    if (!m) {
        cout << -1 << endl;
        exit(0);
    }
    if (!n) {
        cout << 0 << endl;
        exit(0);
    }
    x = gcd(n, m);
    n /= x;
    m /= x;
    while (n != 1 || m != 1) {
        if (n < m) swap(n, m);
        ans += n / m;
        n %= m;
        if (!n) {
            n += m;
            ans--;
        }
        if (n < 1 || m < 1) {
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << ++ans * t << endl;
    return 0;
}
