#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int op, x, a, b, aa, bb;

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> op >> x) {
        (op == 1 ? a : b) += x;

        if (std::abs(a - b) >= 2 && (a >= 25 || b >= 25)) {
            cout << a << ':' << b << endl;
            if (a > b)
                aa++;
            else
                bb++;
            a = 0, b = 0;
        }

        if (aa + bb >= 3) break;
    }

    cout << (aa < bb) + 1 << endl;

    return 0;
}
