#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n, k;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> k >> s;

        auto i = s.find_last_of('1');
        if (i != std::string::npos && n - i - 1 <= k) {
            k -= n - i - 1;
            std::swap(s[n - 1], s[i]);
        }

        auto j = s.find_first_of('1');
        if (j != n - 1) {
            if (j != std::string::npos && j <= k) {
                std::swap(s[0], s[j]);
                k -= j;
            }
        }

        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += std::stoi(s.substr(i - 1, 2));
        }

        cout << ans << endl;
    }

    return 0;
}
