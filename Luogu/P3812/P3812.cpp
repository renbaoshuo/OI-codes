#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;

int n;
long long x, a[N], ans;

void insert(long long x) {
    for (int i = 50; ~i; i--) {
        if (!(x & (1ll << i))) continue;

        if (a[i]) {
            x ^= a[i];
        } else {
            for (int k = 0; k < i; k++) {
                if (x & (1ll << k)) x ^= a[k];
            }

            for (int k = i + 1; k <= 50; k++) {
                if (a[k] & (1ll << i)) a[k] ^= x;
            }

            a[i] = x;
            return;
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

    for (int i = 0; i <= 50; i++) ans ^= a[i];

    cout << ans << endl;

    return 0;
}
