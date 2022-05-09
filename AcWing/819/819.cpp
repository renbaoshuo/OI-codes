#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int f(int x) {
    return x == 1 ? 1 : x * f(x - 1);
}

int n;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    cout << f(n) << endl;

    return 0;
}
