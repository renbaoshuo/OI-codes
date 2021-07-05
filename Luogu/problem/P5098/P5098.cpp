#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x, y, a, b, c, d;
    a = c = -0x3f3f3f3f;
    b = d = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a = max(a, x + y);
        b = min(b, x + y);
        c = max(c, x - y);
        d = min(d, x - y);
    }
    cout << max(a - b, c - d) << endl;
    return 0;
}
