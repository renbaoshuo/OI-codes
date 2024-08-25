#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15;

int n, a[N], ans;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ans = a[0];

    for (int i = 1; i < n; i++) {
        ans = lcm(ans, a[i]);
    }

    cout << ans << endl;

    return 0;
}
