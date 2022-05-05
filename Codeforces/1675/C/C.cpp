#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, sum[N][2], ans;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        ans = 0;

        cin >> s;

        for (int i = 0; i < s.size(); i++) {
            if (i) {
                sum[i][0] = sum[i - 1][0] + (s[i] == '0');
                sum[i][1] = sum[i - 1][1] + (s[i] == '1');
            } else {
                sum[i][0] = s[i] == '0';
                sum[i][1] = s[i] == '1';
            }
        }

        for (int i = 0; i < s.size(); i++) {
            ans += (sum[i][0] - (s[i] == '0')) == 0 && (sum[s.size() - 1][1] == sum[i][1]);
        }

        cout << ans << endl;
    }

    return 0;
}
