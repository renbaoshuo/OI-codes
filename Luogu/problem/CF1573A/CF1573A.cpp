#include <bits/stdc++.h>

using namespace std;

int t, n, ans;
string s;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                ans += s[i] - '0';
                ans += i != n - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
