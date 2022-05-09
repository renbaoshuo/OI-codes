#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int x, y, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> x >> y;

    if (y < x) std::swap(x, y);

    for (int i = x + 1; i < y; i++) {
        if (i & 1) ans += i;
    }

    cout << ans << endl;

    return 0;
}
