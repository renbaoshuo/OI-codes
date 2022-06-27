#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int mid, r, p[N << 1], a[N << 1], b[N << 1], ans;
std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1;

    s2.push_back('^');

    for (const char &c : s1) {
        s2.push_back('#');
        s2.push_back(c);
    }

    s2 += "#$";

    for (int i = 1; i < s2.size(); i++) {
        p[i] = i < r ? std::min(p[mid * 2 - i], r - i) : 1;
        while (s2[i - p[i]] == s2[i + p[i]]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            mid = i;
        }

        a[i + p[i] - 1] = std::max(a[i + p[i] - 1], p[i] - 1);
        b[i - p[i] + 1] = std::max(b[i - p[i] + 1], p[i] - 1);
    }

    for (int i = 3; i <= s2.size() - 4; i += 2) {
        b[i] = std::max(b[i], b[i - 2] - 2);
    }

    for (int i = s2.size() - 4; i >= 3; i -= 2) {
        a[i] = std::max(a[i], a[i + 2] - 2);
    }

    for (int i = 3; i <= s2.size() - 4; i += 2) {
        if (a[i] && b[i]) {
            ans = std::max(ans, a[i] + b[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
