#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, m, a[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        long long t = 0;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cin >> m;

        for (int i = 1, x; i <= m; i++) {
            cin >> x;

            t += x;
        }

        cout << a[t % n + 1] << endl;
    }

    return 0;
}
