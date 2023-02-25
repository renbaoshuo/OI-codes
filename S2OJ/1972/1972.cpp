#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int n, p, f[N][N], d[N], p2[N * N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;

    p2[0] = 1;

    for (int i = 1; i <= n * n; i++) {
        p2[i] = static_cast<long long>(p2[i - 1]) * 2 % p;
    }

    f[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i][1] = p2[(i - 1) * (i - 2) / 2];

        for (int j = 2; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                f[i][j] = (f[i][j] + static_cast<long long>(f[k][j - 1]) * p2[(i - k - 1) * (i - k - 2) / 2] % p) % p;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        d[i] = p2[i * (i + 1) / 2];

        for (int j = 1; j < i; j++) {
            d[i] = ((d[i] - static_cast<long long>(f[i][j]) * d[j]) % p + p) % p;
        }
    }

    cout << d[n] << endl;

    return 0;
}
