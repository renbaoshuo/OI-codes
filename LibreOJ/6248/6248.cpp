#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

long long a, b, c;

inline long long lcm(long long a, long long b) {
    return a / std::__gcd(a, b) * b;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> a >> b >> c;
    cout << lcm(a, lcm(b, c)) << endl;

    return 0;
}
