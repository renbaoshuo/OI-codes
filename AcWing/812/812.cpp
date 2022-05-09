#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, k, x;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    while (n--) {
        cin >> x;

        if (k--) cout << x << ' ';
    }

    cout << endl;

    return 0;
}
