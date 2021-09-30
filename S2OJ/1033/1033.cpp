#include <bits/stdc++.h>

using namespace std;

int t;
bool ans, flag[26][26];
string a, b;

int main() {
    cin >> t;
    getline(cin, a);
    while (t--) {
        memset(flag, 0x00, sizeof(flag));
        getline(cin, a);
        getline(cin, b);
        ans = a.size() == b.size();
        if (ans) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i]) continue;
                if ('a' > a[i] || a[i] > 'z' || 'a' > b[i] || b[i] > 'z') {
                    ans = false;
                    break;
                }
                for (int j = 0; j < 26; j++) {
                    if (flag[a[i] - 'a'][j]) {
                        if (j != b[i] - 'a') {
                            ans = false;
                            break;
                        }
                    }
                }
                flag[a[i] - 'a'][b[i] - 'a'] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
