#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5,
          M = (1 << 10) + 5;

int n, q, a[N], b[N], nxt[N][M];
long long ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = n; i; i--) {
        for (int j = 0; j < 1 << 10; j++) {
            if ((j | a[i]) == j) nxt[i][j] = i;
            else nxt[i][j] = nxt[i + 1][j];
        }
    }

    cin >> q;

    while (q--) {
        int l, r, x;
        long long sum = 0;

        cin >> l >> r >> x;

        l = nxt[l][x];
        while (l && l <= r) {
            sum += b[l];
            l = nxt[l][x -= a[l]];
        }

        ans ^= sum;
    }

    cout << ans << endl;

    return 0;
}
