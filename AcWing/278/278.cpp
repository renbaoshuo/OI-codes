#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 105,
          M = 10005;

int n, m, a[N], f[M];

int main() {
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
