#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int a, b;
double c;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b;
    c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));

    cout << std::fixed << std::setprecision(12) << 1.0 * a / c << ' ' << std::fixed << std::setprecision(12) << 1.0 * b / c << endl;

    return 0;
}
