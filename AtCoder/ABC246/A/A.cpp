#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);

    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x2) {
        cout << x3 << ' ';
    } else if (x1 == x3) {
        cout << x2 << ' ';
    } else {  // x2 == x3
        cout << x1 << ' ';
    }

    if (y1 == y2) {
        cout << y3 << endl;
    } else if (y1 == y3) {
        cout << y2 << endl;
    } else {  // y2 == y3
        cout << y1 << endl;
    }

    return 0;
}
