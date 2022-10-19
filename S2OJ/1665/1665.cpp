#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n;
long long f[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << 1 << endl;

        exit(0);
    }

    f[1] = 1;

    for (int j = 1; j < n; j++) {
        if (j <= 3) {
            for (int i = j + 1; i < n; i++) {
                f[i] = (f[i] + f[j]) % mod;
            }
        } else {
            for (int k = -1; k <= 1; k++) {
                for (int i = j + k; i < n; i += j) {
                    if (j < i) f[i] = (f[i] + f[j]) % mod;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        ans = (ans + f[i]) % mod;
    }

    cout << ans * n % mod << endl;

    return 0;
}
