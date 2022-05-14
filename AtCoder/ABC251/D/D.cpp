#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);

    cout << 297 << endl;

    for (int i = 1; i <= 99; i++) {
        cout << i << ' ';
    }

    for (int i = 100; i <= 9900; i += 100) {
        cout << i << ' ';
    }

    for (int i = 10000; i <= 990000; i += 10000) {
        cout << i << ' ';
    }

    cout << endl;

    return 0;
}
