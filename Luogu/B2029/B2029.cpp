#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const double pi = acos(-1);

int h, r;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> r;

    cout << ceil(20000.0 / (pi * r * r * h)) << endl;

    return 0;
}
