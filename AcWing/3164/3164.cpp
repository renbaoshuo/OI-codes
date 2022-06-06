#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
unsigned long long x, a[N], ans;

inline void insert(unsigned long long x) {
    for (int i = 63; ~i; i--) {
        if (x & (1ull << i)) {
            if (a[i]) {
                x ^= a[i];
            } else {
                a[i] = x;

                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x;

        insert(x);
    }

    for (int i = 63; ~i; i--) {
        if ((ans ^ a[i]) > ans) ans ^= a[i];
    }

    cout << ans << endl;

    return 0;
}
