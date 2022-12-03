#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, x[N], y[N], z[50];
bool flag;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];

        if (i > 1 && flag != std::abs(x[i] + y[i]) % 2) {
            cout << -1 << endl;

            exit(0);
        }

        flag |= std::abs(x[i] + y[i]) % 2;
    }

    m = flag ? 31 : 32;

    cout << m << endl;

    if (flag) {
        for (int i = 30; i; i--) {
            cout << (z[30 - i + 1] = 1 << i) << ' ';
        }
    } else {
        for (int i = 30; ~i; i--) {
            cout << (z[30 - i + 1] = 1 << i) << ' ';
        }
    }

    cout << (z[m] = 1) << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (std::abs(x[i]) > std::abs(y[i])) {
                if (x[i] > 0) {
                    cout << 'R';

                    x[i] -= z[j];
                } else {
                    cout << 'L';

                    x[i] += z[j];
                }
            } else {
                if (y[i] > 0) {
                    cout << 'U';

                    y[i] -= z[j];
                } else {
                    cout << 'D';

                    y[i] += z[j];
                }
            }
        }

        cout << endl;
    }

    return 0;
}
