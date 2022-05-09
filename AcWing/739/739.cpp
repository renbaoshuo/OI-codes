#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

double x;

int main() {
    std::ios::sync_with_stdio(false);

    for (int i = 0; i < 100; i++) {
        cin >> x;

        if (x <= 10) {
            cout << "A[" << i << "] = " << std::fixed << std::setprecision(1) << x << endl;
        }
    }

    return 0;
}
