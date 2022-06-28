#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            int s = 0;

            for (int j = 1; j <= n; j++) {
                if (j != i) {
                    s ^= a[j];
                }
            }

            if (s == a[i]) {
                cout << a[i] << endl;

                break;
            }
        }
    }

    return 0;
}
