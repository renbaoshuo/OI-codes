#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15;

int n, t, a[N << 2], b[N << 2];

bool check() {
    int cnt = 0;

    for (int i = 1; i <= 27; i++) {
        if (b[i] < 0) return false;
        if (b[i] >= 3) {
            b[i] -= 3;
            cnt++;
        }

        if (i % 9 == 0 || i % 9 == 8) continue;

        while (b[i] > 0) {
            b[i]--, b[i + 1]--, b[i + 2]--;
            cnt++;
        }
    }

    return cnt == 4;
}

bool check_hu() {
    bool flag = false;

    for (int i = 1; i <= 27; i++) {
        if (a[i] >= 2) flag = true;
    }

    if (!flag) return false;

    for (int i = 1; i <= 27; i++) {
        if (a[i] < 2) continue;

        std::copy_n(a, N << 2, b);
        b[i] -= 2;

        if (check()) return true;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;

    while (t--) {
        std::fill_n(a, N << 2, 0);

        for (int i = 1; i <= n; i++) {
            std::string s;

            cin >> s;

            int x = s[0] - '0';
            char c = s[1];

            if (c == 'p') x += 9;
            else if (c == 's') x += 18;

            a[x]++;
        }

        if (n == 14) {
            cout << check_hu() << endl;
        } else {  // n == 13
            for (int i = 1; i <= 27; i++) {
                if (a[i] < 4) {
                    a[i]++;

                    if (check_hu()) {
                        cout << (i - 1) % 9 + 1;

                        if (1 <= i && i <= 9) {
                            cout << "m ";
                        } else if (10 <= i && i <= 18) {
                            cout << "p ";
                        } else {  // 19 <= i && i <= 27
                            cout << "s ";
                        }
                    }

                    a[i]--;
                }
            }

            cout << endl;
        }
    }

    return 0;
}
