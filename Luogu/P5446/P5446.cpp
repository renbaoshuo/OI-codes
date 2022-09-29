#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

std::vector<int> manacher(const std::string &_s) {
    int n = _s.size();
    std::string s(n * 2 + 3, '#');

    for (int i = 0; i < n; i++) {
        s[i * 2 + 2] = _s[i];
    }

    s[0] = '^';
    s[n * 2 + 2] = '$';

    std::vector<int> p(s.size(), 1);

    for (int i = 1, mid = 0, r = 0; i <= n * 2 + 1; i++) {
        p[i] = i < r ? std::min(p[mid * 2 - i], r - i) : 1;

        while (s[i - p[i]] == s[i + p[i]]) p[i]++;

        if (i + p[i] - 1 > r) {
            r = i + p[i] - 1;
            mid = i;
        }
    }

    for (int i = 0; i < n; i++) {
        p[i] = p[i * 2 + 2] / 2;
    }

    p.resize(n);

    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        std::string s;

        cin >> s;

        int n = s.size();

        if (n == 1) {
            cout << 1 << endl;

            continue;
        }

        auto p = manacher(s);
        std::vector<int> ans(n);

        for (int i = n - 1; i >= 0; --i) {
            if (i * 2 < n) {
                ans[i] = (p[i] >= i + 1) && ans[i * 2];
            } else {
                ans[i] = p[i] >= n - i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (ans[i]) {
                cout << (i + 1) << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
