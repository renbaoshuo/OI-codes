#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, a, b, x, y;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    while (n--) {
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }

    return 0;
}
