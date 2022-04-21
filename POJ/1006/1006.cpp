#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t, p, e, i, d;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> p >> e >> i >> d, ~p && ~e && ~i && ~d) {
        int l = 21252,
            ans = (5544 * p + 14421 * e + 1288 * i - d + l) % l;
        cout << "Case " << ++t << ": the next triple peak occurs in " << (ans ? ans : l) << " days." << endl;
    }

    return 0;
}
