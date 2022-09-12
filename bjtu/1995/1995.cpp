#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const double d[] = {0, 261.6, 293.6, 329.6, 349.2, 392.0, 440.0, 493.8};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;
    double ans = 0;

    cin >> s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '-') s[i] = s[i - 1];
    }

    for (char c : s) {
        ans += d[c - '0'];
    }

    cout << std::fixed << std::setprecision(6) << ans / s.size() << endl;

    return 0;
}
