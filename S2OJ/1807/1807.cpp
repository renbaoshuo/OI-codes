#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = (1 << 16) + 5;

int t, k, a[17][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int ans = 0, sum = 0;

        cin >> k;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 1 << i; j++) {
                cin >> a[i][j];

                if ((i + k) % 2) {
                    sum ^= a[i][j];
                }
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 1 << i; j++) {
                if ((i + k) % 2) {
                    sum ^= a[i][j];

                    if (sum <= a[i][j]) {
                        ans += 1 + (i != k - 1);
                    }

                    sum ^= a[i][j];
                } else {
                    sum ^= a[i + 1][j << 1];

                    if (a[i + 1][j << 1] <= sum && sum <= a[i + 1][j << 1] + a[i][j]) ans++;

                    sum ^= a[i + 1][j << 1];

                    sum ^= a[i + 1][j << 1 | 1];

                    if (a[i + 1][j << 1 | 1] <= sum && sum <= a[i + 1][j << 1 | 1] + a[i][j]) ans++;

                    sum ^= a[i + 1][j << 1 | 1];
                }
            }
        }

        cout << (sum ? ans : 0) << endl;
    }

    return 0;
}
