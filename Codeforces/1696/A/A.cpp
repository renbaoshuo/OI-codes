#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n, z;
long long a, x;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        a = 0;

        cin >> n >> z;

        for (int i = 1; i <= n; i++) {
            cin >> x;

            a = std::max(a, x | z);
        }

        cout << a << endl;
    }

    return 0;
}
