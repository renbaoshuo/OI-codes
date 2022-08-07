#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int t, a[10], p[10];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        bool flag = false;

        for (int i = 1; i <= 4; i++) {
            cin >> a[i];
        }

        for (a[5] = 0; a[5] <= 9; a[5]++) {
            for (int i = 1; i <= 5; i++) {
                p[i] = i;
            }

            do {
                if (a[p[1]] - 1 == a[p[2]] && a[p[2]] == a[p[3]] + 1 && a[p[4]] == a[p[5]]) flag = true;
            } while (std::next_permutation(p + 1, p + 1 + 5));
        }

        cout << flag << endl;
    }

    return 0;
}
