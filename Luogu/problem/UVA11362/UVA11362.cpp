#include <bits/stdc++.h>

using namespace std;

int t, n;
bool flag;
string s[10005];

int main() {
    cin >> t;
    while (t--) {
        flag = false;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s, s + n);
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1].substr(0, s[i].size()) == s[i]) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "NO" : "YES") << endl;
    }
    return 0;
}
