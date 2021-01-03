#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, sum = 0;
    vector<int> a;
    cin >> n >> x;
    a.push_back(0xc0c0c0c1);
    a.push_back(x);
    sum += x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        int t1 = *--lower_bound(a.begin(), a.end(), x);
        int t2 = *lower_bound(a.begin(), a.end(), x);
        if (t1 == -0x3f3f3f3f) {
            sum += abs(t2 - x);
        } else {
            sum += min(abs(t1 - x), abs(t2 - x));
        }
        a.insert(upper_bound(a.begin(), a.end(), x), x);
    }
    cout << sum << endl;
    return 0;
}
