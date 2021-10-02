#include <bits/stdc++.h>

using namespace std;

int n, k, p, m, x, t;
list<int> a;
list<int>::iterator b[100005];

int main() {
    cin >> n;
    a.push_back(1);
    b[1] = a.begin();
    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        auto it = b[k];
        b[i] = a.insert(p ? next(it) : it, i);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (b[x] != a.end()) {
            a.erase(b[x]);
            b[x] = a.end();
        }
    }
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
