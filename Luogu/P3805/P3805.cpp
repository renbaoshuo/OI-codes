#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

std::vector<int> manacher(std::string _s) {
    // s = "abba" -> "^#a#b#b#a#$"
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

    // for (int i = 0; i < n; i++) {
    //     p[i] = p[i * 2 + 2] / 2;
    // }

    // p.resize(n);

    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;

    cin >> s;

    auto p = manacher(s);

    cout << *std::max_element(p.begin(), p.end()) - 1 << endl;

    return 0;
}
