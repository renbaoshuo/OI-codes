#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        bool flag = false;

        cin >> s;

        std::sort(s.begin(), s.end());

        if (s.find('X') != std::string::npos && s.find('D') != std::string::npos) {
            flag = true;
        }

        int cnt = 1;
        char lst = s[0];
        for (int i = 1; i < s.size(); lst = s[i++]) {
            if (s[i] == lst) {
                cnt++;
            } else {
                if (cnt == 4) flag = true;
                cnt = 1;
            }
        }

        if (cnt == 4) flag = true;

        cout << (flag ? "Yes" : "No") << endl;
    }

    return 0;
}
