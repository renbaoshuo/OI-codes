#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, a, b, c, d, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n--) {
        cin >> a >> b >> c >> d;

        for (int i = 1, j; i <= std::min(b, d); i = j + 1) {
            j = std::min(b / (b / i), d / (d / i));
            if (b / j * j >= a && d / j * j >= c) ans = j;
        }

        cout << ans << endl;
    }

    return 0;
}
