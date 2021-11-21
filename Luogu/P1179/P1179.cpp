#include <bits/stdc++.h>

using namespace std;

int l, r, ans;

int cnt2(int x) {
    int res = 0;
    while (x) {
        res += x % 10 == 2;
        x /= 10;
    }
    return res;
}

int main() {
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        ans += cnt2(i);
    }
    cout << ans << endl;
    return 0;
}
