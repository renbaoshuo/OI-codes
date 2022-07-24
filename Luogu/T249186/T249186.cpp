#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

int t;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        long long l, r, x;

        cin >> l >> r >> x;

        int a = static_cast<long long>(std::floor(static_cast<long double>(l) / x)),
            b = static_cast<long long>(std::floor(static_cast<long double>(r) / x));

        cout << (a == b ? a : 1) << endl;
    }

    return 0;
}
