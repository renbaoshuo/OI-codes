#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, k, max, a[30];
std::string s;

signed main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        max = 0;
        for (int i = 0; i < 26; i++) {
            a[i] = i;
        }

        cin >> n >> k >> s;

        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (x > k) {
                int t = x - (k - max);

                for (int j = x; j >= t; j--) {
                    a[j] = t;
                }

                break;
            }

            for (int j = x; ~j; j--) {
                a[j] = 0;
            }

            max = std::max(max, x);
        }

        for (int i = 0; i < s.size(); i++) {
            cout << char(a[s[i] - 'a'] + 'a');
        }

        cout << endl;
    }

    return 0;
}
