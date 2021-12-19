#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, a, p;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> p;
        if (p < 16) {
            cout << std::max(0, a - 10) << endl;
        } else if (p > 20) {
            cout << std::max(0, a - p + 20) << endl;
        } else {
            cout << a << endl;
        }
    }
    return 0;
}
