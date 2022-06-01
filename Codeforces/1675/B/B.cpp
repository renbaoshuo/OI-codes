#include <iostream>
#include <cmath>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 35;

int t, n, a[N], ans;
bool flag;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        ans = 0;
        flag = false;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        a[n + 1] = std::numeric_limits<int>::max();

        for (int i = n; i; i--) {
            while (a[i] >= a[i + 1]) {
                a[i] = std::floor(1.0 * a[i] / 2);
                ans++;
            }

            if (a[i] == 0 && i != 1) {
                flag = true;
                break;
            }
        }

        cout << (flag ? -1 : ans) << endl;
    }

    return 0;
}
