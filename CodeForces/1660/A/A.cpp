#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, a, b;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << (a ? a + b * 2 + 1 : 1) << endl;
    }
    return 0;
}
