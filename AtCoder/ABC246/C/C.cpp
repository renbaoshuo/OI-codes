#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, k, x, a[N];
long long sum;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    std::sort(a + 1, a + 1 + n, std::greater<int>());
    for (int i = 1, t; i <= n; i++) {
        if (a[i] < x) break;

        t = a[i] / x;
        a[i] %= x;

        if (k > t) {
            k -= t;
            sum -= t * x;
        } else {
            sum -= k * x;
            cout << sum << endl;
            exit(0);
        }
    }

    std::sort(a + 1, a + 1 + n, std::greater<int>());
    for (int i = 1; i <= std::min(n, k); i++) {
        sum -= a[i];
    }

    cout << sum << endl;

    return 0;
}
