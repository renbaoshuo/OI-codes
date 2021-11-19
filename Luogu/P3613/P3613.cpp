#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, map<int, int> > m;
    int n, q, t, i, j, k;
    cin >> n >> q;
    while (q--) {
        cin >> t >> i >> j;
        if (t == 1) {
            cin >> k;
            if (k == 0) {
                if (m.count(i) && m[i].count(j)) {
                    m[i].erase(k);
                    if (m[i].empty()) {
                        m.erase(i);
                    }
                }
            } else {
                m[i][j] = k;
            }
        } else if (t == 2) {
            cout << m[i][j] << endl;
        }
    }
    return 0;
}
