#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int a, b;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b;
    cout << std::__gcd(a, b) << endl;

    return 0;
}
