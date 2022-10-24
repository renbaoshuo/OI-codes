#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, a[N][26];
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;

    s = ' ' + s;

    for (int i = 1; i < s.size(); i++) {
        std::copy_n(a[i - 1], 26, a[i]);

        a[i][s[i] - 'a']++;
    }

    for (int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;

        if (s[l] != s[r] || l == r) {
            cout << "Yes" << endl;

            continue;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (a[r][i] - a[l - 1][i] > 0) {
                cnt++;
            }
        }

        cout << (cnt < 3 ? "No" : "Yes") << endl;
    }

    return 0;
}
