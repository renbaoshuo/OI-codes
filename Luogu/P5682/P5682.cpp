#include <bits/stdc++.h>

using namespace std;

int n, t, a[200005];

int main() {
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
    }
    if (s.size() <= 1) {
        cout << -1 << endl;
    } else {
        t = 0;
        for (int i : s) {
            a[++t] = i;
        }
        cout << max(a[t - 2], a[t] % a[t - 1]) << endl;
    }
    return 0;
}
