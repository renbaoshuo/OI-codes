#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

long long n, k, ans;

int main() {
    cin >> n >> k;
    ans = n * k;
    for (int x = 1, gx; x <= n; x = gx + 1) {
        gx = k / x ? std::min(k / (k / x), n) : n;
        ans -= (k / x) * (x + gx) * (gx - x + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
