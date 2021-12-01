#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, m, l, r, c, b[100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        b[i] += c;
        b[i + 1] -= c;
    }
    while (m--) {
        cin >> l >> r >> c;
        b[l] += c;
        b[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
