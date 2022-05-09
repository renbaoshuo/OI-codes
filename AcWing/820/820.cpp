#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int f(int x) {
    return x == 1 || x == 2 ? 1 : f(x - 1) + f(x - 2);
}

int n;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    cout << f(n) << endl;

    return 0;
}
