#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, k, a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int cnt = 0;

        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 2; i < n; i++) {
            if (a[i - 1] + a[i + 1] < a[i]) cnt++;
        }

        if (k == 1) {
            cout << (n - 1) / 2 << endl;
        } else {
            cout << cnt << endl;
        }
    }

    return 0;
}
