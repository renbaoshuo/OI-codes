#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

long long n, k, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    ans = n * k;

    for (long long l = 1, r; l <= n; l = r + 1) {
        if (k / l) {
            r = std::min(k / (k / l), n);
        } else {
            r = n;
        }

        ans -= (r + l) * (k / l) * (r - l + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
