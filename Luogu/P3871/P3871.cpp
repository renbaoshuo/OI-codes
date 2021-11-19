#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, t;
    string op;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        nums.insert(lower_bound(nums.begin(), nums.end(), t), t);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "add") {
            cin >> t;
            nums.insert(lower_bound(nums.begin(), nums.end(), t), t);
        } else {
            cout << nums[nums.size() / 2 - (nums.size() & 1 ^ 1)] << endl;
        }
    }
    return 0;
}
