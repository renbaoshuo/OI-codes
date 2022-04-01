#include <bits/stdc++.h>

using namespace std;

int t, ans;
string kbd, s;
map<char, int> key;

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> kbd >> s;
        for (int i = 0; i < kbd.size(); i++) {
            key[kbd[i]] = i;
        }
        for (int i = 1; i < s.size(); i++) {
            ans += abs(key[s[i]] - key[s[i - 1]]);
        }
        cout << ans << endl;
    }
    return 0;
}
