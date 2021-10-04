#include <bits/stdc++.h>

using namespace std;

int n, x;
set<pair<int, int>> s;

int main() {
    cin >> n;
    s.insert({make_pair(INT_MIN, 0), make_pair(INT_MAX, 0)});
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i > 1) {
            auto it1 = s.upper_bound(make_pair(x, 0));
            auto it2 = it1--;
            long long x1 = 0ll + x - it1->first;
            long long x2 = 0ll + it2->first - x;
            if (x1 <= x2) {
                cout << x1 << ' ' << it1->second << endl;
            } else {
                cout << x2 << ' ' << it2->second << endl;
            }
        }
        s.insert(make_pair(x, i));
    }
    return 0;
}
