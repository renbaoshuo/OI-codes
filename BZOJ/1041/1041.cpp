#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, ans = 1;

    cin >> r;

    for (int i = 2; i * i <= r; i++) {
        if (r % i == 0) {
            int cnt = 0;

            while (r % i == 0) {
                r /= i;
                cnt++;
            }

            if (i % 4 == 1) ans *= cnt * 2 + 1;
        }
    }

    if (r != 1 && r % 4 == 1) {
        ans *= 3;
    }

    cout << ans * 4 << endl;

    return 0;
}
