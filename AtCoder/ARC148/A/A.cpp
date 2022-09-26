#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    std::sort(a + 1, a + 1 + n);

    for (int i = 2; i <= n; i++) {
        ans = std::__gcd(ans, a[i] - a[i - 1]);
    }

    cout << (ans == 1 ? 2 : 1) << endl;

    return 0;
}
