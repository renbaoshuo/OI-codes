#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, opt;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> opt >> x;
        if (opt == 1) {
            a.insert(lower_bound(a.begin(), a.end(), x), x);
        } else if (opt == 2) {
            a.erase(lower_bound(a.begin(), a.end(), x));
        } else if (opt == 3) {
            cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << endl;
        } else if (opt == 4) {
            cout << a[x - 1] << endl;
        } else if (opt == 5) {
            cout << *--lower_bound(a.begin(), a.end(), x) << endl;
        } else if (opt == 6) {
            cout << *upper_bound(a.begin(), a.end(), x) << endl;
        }
    }
    return 0;
}