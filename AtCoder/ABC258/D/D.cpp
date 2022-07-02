#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, x, a, b;
long long sum, ans = std::numeric_limits<long long>::max();

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;

    for (int i = 1; i <= std::min(x, n); i++) {
        cin >> a >> b;

        sum += a + b;
        ans = std::min(ans, sum + 1ll * (x - i) * b);
    }

    cout << ans << endl;

    return 0;
}
