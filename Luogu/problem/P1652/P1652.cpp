#include <bits/stdc++.h>

using namespace std;

double dis(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n, x1, y1, x2, y2, ans = 0, x[60], y[60], r[60];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++) {
        if ((dis(x1, y1, x[i], y[i]) < r[i]) ^ (dis(x2, y2, x[i], y[i]) < r[i])) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
