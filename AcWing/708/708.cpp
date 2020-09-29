#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);

    for (int i = 2; i <= 100; i += 2) {
        cout << i << endl;
    }

    return 0;
}
