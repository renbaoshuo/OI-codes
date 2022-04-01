#include <bits/stdc++.h>

using namespace std;

int t, n, a, b;
bool flag, flag_a, flag_b;
vector<int> ans_left, ans_right;

int main() {
    cin >> t;
    while (t--) {
        flag = flag_a = flag_b = false;
        ans_left.clear();
        ans_right.clear();
        cin >> n >> a >> b;
        for (int i = n; i > 0; i--) {
            if (i == a) {
                ans_left.push_back(i);
                flag_a = true;
            } else if (i == b) {
                ans_right.push_back(i);
                flag_b = true;
            } else if (i > a && ans_left.size() + !flag_a < n / 2) {
                ans_left.push_back(i);
            } else if (i < b && ans_right.size() + !flag_b < n / 2) {
                ans_right.push_back(i);
            } else {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << -1 << endl;
        } else {
            for (int ans : ans_left) {
                cout << ans << ' ';
            }
            for (int ans : ans_right) {
                cout << ans << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
