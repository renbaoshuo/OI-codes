#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int a, b;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b;

    cout << "O JOGO DUROU " << b - a + 24 * (a >= b) << " HORA(S)" << endl;

    return 0;
}
