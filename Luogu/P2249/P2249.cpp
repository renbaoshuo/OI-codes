#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, m;
    vector<int> nums;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), t);
        if (*it == t) {
            cout << it - nums.begin() + 1 << ' ';
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}
