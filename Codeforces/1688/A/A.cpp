#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, x, y;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> x;

        int k = 0;
        while (!((x >> k) & 1) && k <= 30) k++;
        y = 1 << k;  // 此时满足 (x & y) > 0

        if ((x ^ y) <= 0) {
            int k = 0;
            while (((x >> k) & 1) && k <= 30) k++;
            y += 1 << k;  // 此时满足 (x ^ y) > 0
        }

        cout << y << endl;
    }

    return 0;
}
