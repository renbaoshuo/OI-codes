#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 30;

int n, q;
long long a[N][N];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ((i & 1ll) << (i + j)) << ' ';
        }

        cout << endl;
    }

    cout << std::flush;

    cin >> q;

    while (q--) {
        long long x;

        cin >> x;

        int xx = 0, yy = 0;

        cout << 1 << ' ' << 1 << endl;

        for (int i = 1; i <= n * 2 - 2; i++) {
            if (((x >> i) & 1) == (xx & 1)) yy++;
            else xx++;

            cout << xx + 1 << ' ' << yy + 1 << endl;
        }

        cout << std::flush;
    }
}
