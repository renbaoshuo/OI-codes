#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int v, a, b, c;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> v >> a >> b >> c;
    v %= a + b + c;
    if (v < a) {
        cout << "F" << endl;
    } else if (v < a + b) {
        cout << "M" << endl;
    } else {
        cout << "T" << endl;
    }
    return 0;
}
