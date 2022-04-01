#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int t, n;
string s[2];
bool flag;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        flag = true;
        cin >> n >> s[0] >> s[1];
        for (int i = 0; i < n; i++) {
            if (s[0][i] == '1' && s[1][i] == '1') {
                flag = false;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
