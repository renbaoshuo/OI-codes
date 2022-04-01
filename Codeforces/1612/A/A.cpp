#include <bits/stdc++.h>

using namespace std;

int t, x, y, n, xx, yy;

inline int d(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    cin >> t;
    while (t--) {
        bool flag = false;
        cin >> x >> y;
        n = x + y;
        for (int i = 0; i * 2 <= n; i++) {
            xx = i;
            yy = (n >> 1) - i;
            if ((x + y) / 2.0 == xx + yy && (x + y) / 2.0 == d(x, y, xx, yy)) {
                cout << xx << ' ' << yy << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "-1 -1" << endl;
        }
    }
    return 0;
}
