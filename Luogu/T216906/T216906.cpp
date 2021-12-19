#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, h, e;

int main() {
    cin >> t >> h >> e;
    cout << (int)floor(0.2 * t + 0.3 * h + 0.5 * e) << endl;
    return 0;
}
