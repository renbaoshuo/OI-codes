#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

long long a, b, c, ans;

int main() {
    cin >> a >> b;
    a ^= 9961, b ^= 9961;
    a += 17;
    b += a + 17;
    a *= 81, b *= 81;
    c = a + b - 4;
    ans = (c / 10) * 10 + 1;
    cout << ans % 9 << endl;
    return 0;
}
