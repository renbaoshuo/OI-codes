#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1.1e7 + 5;

int p[N << 1], mid, r, ans;
std::string s1, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1;

    // Init

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
    }

    for (int i = 0; i < s2.size(); i++) {
        ans = std::max(ans, p[i]);
    }

    cout << ans - 1 << endl;

    return 0;
}
