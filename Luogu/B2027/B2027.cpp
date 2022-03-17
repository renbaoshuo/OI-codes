#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const double pi = 3.14;

double r;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> r;
    cout << std::fixed << std::setprecision(5) << 4.0 / 3.0 * pi * r * r * r << endl;
    return 0;
}
