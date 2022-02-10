#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

int t, n, m;
long long q;

inline long long lcm(int a, int b) {
    return 1ll * a * b / std::__gcd(a, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        long long ans = 0;
        cin >> n >> m >> q;
        for (long long y = 0; y <= std::min(lcm(n, m) - 1, q) / m; y++) {
            ans += (q - y * m) / n + 1;
        }
        cout << q - ans + 1 << endl;
    }
    return 0;
}
