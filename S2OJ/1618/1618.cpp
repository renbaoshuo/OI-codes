#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int l, r;

        cin >> l >> r;

        cout << r - l + 1 << endl;
    }

    return 0;
}
