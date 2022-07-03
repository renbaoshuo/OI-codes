#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20;

int n, m, a[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 1 << n; i++) {
        if (__builtin_popcount(i) == n - m) {
            std::bitset<2005> s;
            s[0] = 1;

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    s |= s << a[j];
                }
            }

            ans = std::max(ans, (int)s.count());
        }
    }

    cout << ans - 1 << endl;

    return 0;
}
