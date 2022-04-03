#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int m, n, w[N], v[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j; j--) {
            f[j] = std::max(f[j], j >= w[i] ? f[j - w[i]] + v[i] : f[j]);
        }
    }

    cout << f[m] << endl;

    return 0;
}
