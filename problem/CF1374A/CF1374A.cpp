#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, n, ans = 0;
        cin >> x >> y >> n;
        cout << (n - y) / x * x + y << endl;
    }
    return 0;
}
