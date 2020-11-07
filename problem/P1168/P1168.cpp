#include <bits/stdc++.h>

using namespace std;

int main() {
    int         n, t;
    vector<int> a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a.insert(upper_bound(a.begin(), a.end(), t), t);
        if (i % 2) {
            cout << a[(i - 1) / 2] << endl;
        }
    }
    return 0;
}
