#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e7 + 5;

int n, pos[N], x, y;
long long ans = std::numeric_limits<long long>::max();

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, t; i <= n; i++) {
        cin >> t;

        if (pos[t] && t < ans) {
            ans = t;
            x = pos[t];
            y = i;
        }

        pos[t] = i;
    }

    for (int i = 1; i <= 1e7; i++) {
        int t = 0;

        for (int j = i; j <= 1e7; j += i) {
            if (!pos[j]) continue;

            if (!t) {
                t = j;
            } else {
                long long lcm = 1ll * t * j / i;

                if (lcm < ans) {
                    ans = lcm;
                    x = pos[t];
                    y = pos[j];
                }

                break;
            }
        }
    }

    cout << std::min(x, y) << ' ' << std::max(x, y) << endl;

    return 0;
}
