#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int x, y;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> x >> y;
    cout << std::max(x, y) << endl;

    return 0;
}
