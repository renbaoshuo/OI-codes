#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        int ans = 0;

        cin >> n >> s;

        for (int i = 1, t = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                if (t & 1) {
                    s[i] = s[i - 1];
                    ans++;
                    t++;
                } else {
                    t = 1;
                }
            } else {
                t++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
