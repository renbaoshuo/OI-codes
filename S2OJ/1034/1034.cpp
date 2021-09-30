#include <bits/stdc++.h>

using namespace std;

int n, l, x, ans;
set<int> s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.end()) {
            ans++;
        } else {
            s.erase(*it);
        }
        s.insert(x);
    }
    cout << ans << endl;
    return 0;
}
