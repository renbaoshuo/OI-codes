#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

double a, b;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> a >> b;
    cout << fmod(a, b) << endl;
    return 0;
}
