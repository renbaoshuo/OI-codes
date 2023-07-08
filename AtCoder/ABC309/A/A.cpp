#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;

    cin >> a >> b;

    cout << (b - a == 1 && a != 3 && a != 6 && a != 9 && b != 1 && b != 4 && b != 7 ? "Yes" : "No") << endl;

    return 0;
}
