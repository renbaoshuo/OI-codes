#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, res = 1;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    while (res *= n--, n) {}

    cout << res << endl;

    return 0;
}
