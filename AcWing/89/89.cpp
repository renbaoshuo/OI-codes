#include <bits/stdc++.h>

using namespace std;

long long a, b, p, ans = 1;

int main() {
    cin >> a >> b >> p;
    a %= p;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    cout << ans % p << endl;
    return 0;
}
