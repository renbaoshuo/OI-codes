#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 233333 + 5;
const int mod = 1e9 + 7;

int n, f[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        for (int j = x - 1 & x; j; j = j - 1 & x) {
            f[j] = (f[j] + f[x] + 1) % mod;
        }

        ans = (ans + f[x]) % mod;
    }

    cout << ans << endl;

    return 0;
}
