#include <iostream>
#include <cmath>
#include <experimental/numeric>

using std::cin;
using std::cout;
const char endl = '\n';

int n, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        ans = std::experimental::gcd(ans, std::abs(x));
    }

    cout << ans << endl;

    return 0;
}
