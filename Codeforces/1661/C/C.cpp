#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int t, n;
long long max, sum, x, a[N], b[N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        ans = std::numeric_limits<long long>::max();
        max = 0;

        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            max = std::max(max, a[i]);
        }

        for (int _ = 1; _ <= 2; _++, max++) {
            sum = x = 0;

            for (int i = 1; i <= n; i++) {
                b[i] = max - a[i];
            }

            for (int i = 1; i <= n; i++) {
                sum += b[i] / 2 * 2;
                x += b[i] % 2;
            }

            if (x * 2 > sum) {
                ans = std::min(ans, x * 2 - 1);
            } else {
                sum -= x * 2;
                ans = std::min(ans, x * 2 + sum / 3 * 2 + sum % 3);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
