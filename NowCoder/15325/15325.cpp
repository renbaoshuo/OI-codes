#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, ans = 1;

        cin >> n;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;

                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }

                ans *= cnt * 2 + 1;
            }
        }

        if (n > 1) ans *= 3;

        cout << ans / 2 + 1 << endl;
    }

    return 0;
}
