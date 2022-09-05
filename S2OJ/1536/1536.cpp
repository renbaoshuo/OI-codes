#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20005;

int n, ans;
std::string s, t;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;

    int s_len = s.size();

    for (int i = 1; i <= n; i++) {
        cin >> t;

        int t_len = t.size();

        if (s_len == t_len) {
            bool flag = true;

            for (int i = 0; i < t_len; i++) {
                if (s[i] != '#') {
                    flag &= s[i] == t[i];
                }
            }

            if (flag) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
