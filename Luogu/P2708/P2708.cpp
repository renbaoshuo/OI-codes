#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = s.size() - 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            ans--;
        }
    }
    if (s[s.size() - 1] == '0') {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
