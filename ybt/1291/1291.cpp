#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, a[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i]; j--) {
            f[j] += f[j - a[i]];
        }
    }

    cout << f[m] << endl;

    return 0;
}
