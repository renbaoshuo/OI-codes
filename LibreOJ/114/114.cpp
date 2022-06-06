#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int n, m, cnt;
unsigned long long x, k, a[N], p[N], ans;

inline void insert(unsigned long long x) {
    for (int i = 50; ~i; i--) {
        if (x & (1ull << i)) {
            if (a[i]) {
                x ^= a[i];
            } else {
                for (int k = 0; k < i; k++) {
                    if (x & (1ull << k)) x ^= a[k];
                }

                for (int k = i + 1; k <= 50; k++) {
                    if (a[k] & (1ull << i)) a[k] ^= x;
                }

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

    for (int i = 0; i <= 50; i++) {
        if (a[i]) p[cnt++] = a[i];
    }

    cin >> m;

    while (m--) {
        cin >> k;

        if (cnt != n) k--;  // 非空

        if (k >= (1ull << cnt)) {
            cout << -1 << endl;
        } else {
            ans = 0;

            for (int i = 0; i < cnt; i++) {
                if (k & (1ull << i)) ans ^= p[i];
            }

            cout << ans << endl;
        }
    }

    return 0;
}
