#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int t, n, m;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        int ans = 0;

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            m -= x;

            if (m < 0) {
                ans += -m;
                m = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
