#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

long long n, k, ans;

int main() {
    cin >> n >> k;
    ans = n * k;
    for (int x = 1; x <= n; x++) {
        ans -= floor(1.0 * k / x) * x;
    }
    cout << ans << endl;
    return 0;
}
