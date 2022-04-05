#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 4005;
const long long mod = 2147483648;

int n;
long long f[N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }

    cout << f[n] - 1 << endl;

    return 0;
}
