#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5,
          M = 2e6 + 5;

int n, m, a[N], s[N], l[M], r[M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        char c;

        cin >> c;

        a[i] = c == 'T' ? 2 : 1;
    }

    for (int i = n; i; i--) {
        s[i] = a[i] == 2 ? s[i + 1] + 1 : 0;
    }

    for (int i = 1, sum = 0; i <= n; i++) {
        sum += a[i];
        l[sum] = 1, r[sum] = i;

        if (a[i] == 2) {
            if (s[i] > s[1]) {
                l[sum - 1] = s[1] + 2;
                r[sum - 1] = s[1] + i;
            } else if (s[i] != n - i + 1) {
                l[sum - 1] = s[i] + 1;
                r[sum - 1] = s[i] + i;
            }
        }
    }

    while (m--) {
        int k;

        cin >> k;

        if (!l[k]) {
            cout << "NIE" << endl;
        } else {
            cout << l[k] << ' ' << r[k] << endl;
        }
    }

    return 0;
}
