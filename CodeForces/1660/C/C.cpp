#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, ans, f[N][2], pre[N], last[N];
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        ans = 0;
        memset(f, 0x00, sizeof(f));
        memset(last, 0x00, sizeof(last));

        cin >> s;
        s = ' ' + s;

        for (int i = 1; i < s.size(); i++) {
            pre[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        for (int i = 1; i < s.size(); i++) {
            f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
            if (pre[i]) {
                f[i][1] = f[pre[i]][0] + 2;
            }
            ans = std::max({ans, f[i][0], f[i][1]});
        }

        cout << s.size() - ans - 1 << endl;
    }

    return 0;
}
