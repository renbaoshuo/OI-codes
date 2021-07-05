#include <bits/stdc++.h>

using namespace std;

int n, m, op, l, r, k, d, p, a[100005];

int main() {
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for(int i = 0 ; i < m ; i++) {
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> k >> d;
            for(int j = l ; j <= r ; j++) {
                a[j] += k + (j - l) * d;
            }
        } else if(op == 2) {
            cin >> p;
            cout << a[p] << endl;
        }
    }
    return 0;
}
