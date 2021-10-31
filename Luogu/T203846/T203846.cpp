#include <bits/stdc++.h>

using namespace std;

long long a, b, c, ans;

int main() {
    cin >> a >> b >> c;
    if (a == 1 || b == 1) {
        cout << -1 << endl;
        exit(0);
    }
    while (a <= c) {
        a *= b;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
