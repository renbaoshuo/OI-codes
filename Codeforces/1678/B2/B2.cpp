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
        int ans1 = 0, ans2 = 0;

        cin >> n >> s;

        int p = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] ^ s[i + 1]) {  // 二元组内不相同
                ans1++;
            } else if (s[i] != p) {  // 新的一段
                ans2++;
                p = s[i];
            }
        }

        cout << ans1 << ' ' << std::max(1, ans2) << endl;
    }

    return 0;
}
