#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, a, b, m, x, y;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);

    y -= a / b * x;

    return d;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    while (n--) {
        cin >> a >> b >> m;

        int d = exgcd(a, m, x, y);

        if (b % d) {
            cout << "impossible" << endl;
        } else {
            cout << 1ll * b / d * x % m << endl;
        }
    }

    return 0;
}
