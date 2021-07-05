#include <bits/stdc++.h>

using namespace std;

struct node {
    int x1, x2, y;

    node() {
        x1 = x2 = 0;
    }
    node(int _x1, int _x2, int _y) {
        x1 = _x1;
        x2 = _x2;
        y = _y;
    }

    const bool operator<(const node& b) {
        return y < b.y;
    }
} a[1005];

int main() {
    int n, ans = 0, h1, h2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].y >> a[i].x1 >> a[i].x2;
    }
    for (int i = 1; i <= n; i++) {
        h1 = h2 = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j || a[i].y < a[j].y) {
                continue;
            }
            if (a[i].x1 < a[j].x2 && a[i].x1 >= a[j].x1) {
                h1 = max(h1, a[j].y);
            }
            if (a[i].x2 <= a[j].x2 && a[i].x2 > a[j].x1) {
                h2 = max(h2, a[j].y);
            }
        }
        ans += a[i].y * 2 - h1 - h2;
    }
    cout << ans << endl;
    return 0;
}
