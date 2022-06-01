#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

int a, b, c, x;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> c >> x;
    if (x <= a) {
        cout << 1 << endl;
    } else if (x > b) {
        cout << 0 << endl;
    } else {
        cout << std::fixed << std::setprecision(10) << 1.00 * c / (b - a) << endl;
    }
    return 0;
}
