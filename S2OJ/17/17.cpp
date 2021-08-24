#include <bits/stdc++.h>

using namespace std;

int t, n, ans;
string s;
bool flag;
char last;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> s;
        while (!s.empty()) {
            flag = false;
            for (int i = 1; i < s.size(); i++) {
                if (s[i - 1] == s[i]) {
                    s.erase(s.begin() + i);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                s.erase(--s.end());
            }
            ans++;
            last = *s.begin();
            while (!s.empty() && last == *s.begin()) {
                s.erase(s.begin());
            }
        }
        cout << ans << endl;
    }
    return 0;
}
