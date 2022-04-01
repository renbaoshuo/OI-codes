#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (is_sorted(s.begin(), s.end())) {
            cout << 0 << endl;
            continue;
        }
        int cnt = count(s.begin(), s.end(), '1');
        s = ' ' + s;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (i < n - cnt + 1 && s[i] == '1' || i >= n - cnt + 1 && s[i] == '0') {
                ans.push_back(i);
            }
        }
        cout << 1 << endl;
        cout << ans.size() << ' ';
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
