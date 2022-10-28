#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e6 + 5;

int n, p, inv[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;

    inv[0] = 0;
    inv[1] = 1;

    cout << inv[1] << endl;

    for (int i = 2; i <= n; i++) {
        inv[i] = p - static_cast<long long>(p) / i * inv[p % i] % p;

        cout << inv[i] << endl;
    }

    return 0;
}
